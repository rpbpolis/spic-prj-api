#ifndef BANJO_GAME_SERIALIZATION_HPP
#define BANJO_GAME_SERIALIZATION_HPP

#include <nlohmann/json.hpp>

namespace spic::serialization {
    template <typename T>
    void Serialize(T data, const std::string& path) {
        nlohmann::json json;
//        json << data;

        std::cout << "need to serialize to: " << path << '\n';
    }

    template<typename T>
    T Deserialize(const std::string& path) {
        std::cout << "need to serialize from: " << path << '\n';
        return {};
    }
}

#endif
