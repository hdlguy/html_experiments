#include "cpp-httplib/httplib.h"
#include "libinstrument.h"
#include <nlohmann/json.hpp> // For JSON responses (optional)
#include <iostream>
#include <vector>
#include <mutex>

using json = nlohmann::json;
std::mutex fpga_mutex;

int main() {

    if (fpga_init() != 0) {
        std::cerr << "FPGA init failed\n";
        return 1;
    }

    httplib::Server svr;

    // GET /api/status
    svr.Get("/api/status", [](const httplib::Request&, httplib::Response& res) {
        std::lock_guard<std::mutex> lock(fpga_mutex);
        uint32_t value = 0;
        fpga_read_reg(0x00, &value);
        json j = { {"status_reg", value} };
        res.set_content(j.dump(), "application/json");
    });

    // POST /api/start
    svr.Post("/api/start", [](const httplib::Request&, httplib::Response& res) {
        std::lock_guard<std::mutex> lock(fpga_mutex);
        fpga_start_acquisition();
        res.set_content(R"({"result": "started"})", "application/json");
    });

//    // GET /api/data
//    svr.Get("/api/data", [](const httplib::Request&, httplib::Response& res) {
//        std::lock_guard<std::mutex> lock(fpga_mutex);
//        const size_t length = 1024;
//        std::vector<float> buffer(length);
//        fpga_read_vector(buffer.data(), length);
//        json j = { {"data", buffer} };
//        res.set_content(j.dump(), "application/json");
//    });

    std::cout << "Server running on http://0.0.0.0:5000\n";
    svr.listen("0.0.0.0", 5000);

    return 0;
}

