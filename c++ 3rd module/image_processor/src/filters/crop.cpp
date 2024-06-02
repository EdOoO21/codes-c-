#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "filter.h"
#include "registry.h"

namespace image_processor::filters {

namespace {

size_t Cast(std::string_view s) {
    std::stringstream sstream(s.data());
    size_t result = 0;
    sstream >> result;
    return result;
}

}  // namespace

class Crop : public Filter {
public:
    class Factory : public Filter::Factory {
    public:
        std::unique_ptr<Filter> Construct(const std::vector<std::string>& parameters) override {
            if (parameters.size() != 2) {
                throw std::invalid_argument("");
            }

            const size_t width = Cast(parameters[0]);
            const size_t height = Cast(parameters[1]);
            return std::make_unique<Crop>(width, height);
        }
    };

public:
    Crop(size_t width, size_t height) : width_(width), height_(height) {
        std::cout << width << height << std::endl;
    }

    image::Image Apply(const image::Image& image) override {
        return image;
    }

private:
    [[maybe_unused]] size_t width_;
    [[maybe_unused]] size_t height_;
};

REGISTER_FILTER("crop", Crop::Factory)

}  // namespace image_processor::filters
