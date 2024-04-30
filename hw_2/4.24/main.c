#include <iostream>
#include <random>
#include <thread>
#include <vector>

int number_of_points_in_circle = 0;

struct Point 
{
    double x;
    double y;
};

std::vector<Point> generated_points;

void generate_points(int how_many) {
    std::random_device dev{};
    std::mt19937 rng{dev()};
    std::uniform_real_distribution<> distribution(-1, 1);

    for (int i = 0; i < how_many; ++i) {
        double x = distribution(rng);
        double y = distribution(rng);
        generated_points.emplace_back(Point{x, y});
    }

    for (const auto& point : generated_points) {
        if (std::sqrt(point.x * point.x + point.y * point.y) <= 1) {
            number_of_points_in_circle++;
        }
    }
}

int main() {
    std::cout << "How many points would you like to generate?\n";
    int number;
    std::cin >> number;

    std::thread t1(generate_points, number);
    t1.join();

    double pi_estimation = 4.0 * static_cast<double>(number_of_points_in_circle) / generated_points.size();
    std::cout << "Pi estimation: " << pi_estimation << '\n';

    return 0;
}
