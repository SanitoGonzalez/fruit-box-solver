#pragma once

#include <array>
#include <cstdint>
#include <iostream>
#include <random>

struct Position {
    size_t x, y;
};

class Board {
public:
    static constexpr size_t Height = 10, Width = 17;
    using Container = std::array<std::array<uint8_t, Width>, Height>;

    static Board generate();

    void display() const;

    [[nodiscard]] const Container& data() const { return _data; }

private:
    Container _data{};
};

inline Board Board::generate() {
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<uint8_t> dist{1, 9};

    Board board{};
    for (auto& row : board._data)
        for (auto& number : row)
            number = dist(gen);

    return board;
}

inline void Board::display() const {
    for (const auto& row : _data) {
        for (const auto& number : row)
            std::cout << static_cast<int>(number) << ' ';
        std::cout << '\n';
    }
}
