#include <httplib.h>
#include <iostream>
#include <string>
#include <atomic>

// Simple counters
static std::atomic<uint64_t> contact_requests{0};
static std::atomic<uint64_t> health_requests{0};

int main()
{
    httplib::Server svr;

    svr.Get("/api/health", [](const httplib::Request&, httplib::Response& res) {
        health_requests++;
        res.set_content(R"({"status":"ok"})", "application/json");
    });

    svr.Post("/api/contact", [](const httplib::Request& req, httplib::Response& res) {
        contact_requests++;
        std::cout << "Contact request body: " << req.body << "\n";
        res.set_content(R"({"message":"Thank you, we will be in touch!"})", "application/json");
    });

    // Prometheus metrics endpoint
    svr.Get("/metrics", [](const httplib::Request&, httplib::Response& res) {
        std::string body;
        body += "# HELP acme_contact_requests_total Total contact form submissions\n";
        body += "# TYPE acme_contact_requests_total counter\n";
        body += "acme_contact_requests_total " + std::to_string(contact_requests.load()) + "\n";
        body += "# HELP acme_health_requests_total Total health check requests\n";
        body += "# TYPE acme_health_requests_total counter\n";
        body += "acme_health_requests_total " + std::to_string(health_requests.load()) + "\n";
        res.set_content(body, "text/plain; version=0.0.4");
    });

    svr.Options("/api/.*", [](const httplib::Request&, httplib::Response& res) {
        res.set_header("Access-Control-Allow-Origin",  "*");
        res.set_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
        res.set_header("Access-Control-Allow-Headers", "Content-Type");
        res.status = 204;
    });

    svr.set_post_routing_handler([](const httplib::Request&, httplib::Response& res) {
        res.set_header("Access-Control-Allow-Origin", "*");
    });

    const std::string host = "0.0.0.0";
    const int         port = 8080;
    std::cout << "Acme Co backend listening on http://" << host << ":" << port << "\n";

    if (!svr.listen(host, port)) {
        std::cerr << "Failed to start server\n";
        return 1;
    }
    return 0;
}