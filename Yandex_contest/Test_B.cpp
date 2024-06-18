#include "gtest/gtest.h"
#include "TestContest_B.h.."

TEST(BasicTests, Test_1) {
    std::stringstream output_stream;
    std::stringstream input_stream("8\n"
                                   "50 7 25 3632 A\n"
                                   "14 23 52 212372 S\n"
                                   "15 0 5 3632 C\n"
                                   "14 21 30 212372 A\n"
                                   "50 7 26 3632 C\n"
                                   "14 21 30 3632 A\n"
                                   "14 21 40 212372 B\n"
                                   "14 23 52 3632 B");
    std::streambuf *orig_cin = std::cin.rdbuf(input_stream.rdbuf()); // Перенаправляем cin на наш поток
    std::streambuf *orig_cout = std::cout.rdbuf(output_stream.rdbuf()); // Перенаправляем cout на наш поток

    Init(); // Вызываем вашу функцию

    std::cin.rdbuf(orig_cin); // Восстанавливаем cin обратно
    std::cout.rdbuf(orig_cout); // Восстанавливаем cout обратно

    EXPECT_EQ(output_stream.str(), "156 142 "); // Проверяем вывод
}

TEST(BasicTests, Test_2) {
    std::stringstream output_stream;
    std::stringstream input_stream("8\n"
                                   "50 7 25 3632 A\n"
                                   "14 23 52 212372 S\n"
                                   "15 0 5 3632 C\n"
                                   "14 21 30 212372 A\n"
                                   "50 7 26 3632 C\n"
                                   "14 21 30 3632 A\n"
                                   "14 21 40 212372 B\n"
                                   "14 23 52 3632 B");
    std::streambuf *orig_cin = std::cin.rdbuf(input_stream.rdbuf()); // Перенаправляем cin на наш поток
    std::streambuf *orig_cout = std::cout.rdbuf(output_stream.rdbuf()); // Перенаправляем cout на наш поток

    Init(); // Вызываем вашу функцию

    std::cin.rdbuf(orig_cin); // Восстанавливаем cin обратно
    std::cout.rdbuf(orig_cout); // Восстанавливаем cout обратно

    EXPECT_EQ(output_stream.str(), "156 142 "); // Проверяем вывод
}