#include <iostream>

#include <Eigen/Dense>

#include "main.h"

extern UART_HandleTypeDef huart2;

extern "C" void cppmain() {
  Eigen::Matrix2f A;
  A << 1, 2, 3, 4;
  auto A_2 = A * A;

  while (true) {
    std::cout << A_2 << std::endl;
    HAL_Delay(1000);
  }
}

extern "C" int _write([[maybe_unused]] int file, char *ptr, int len) {
  HAL_UART_Transmit(&huart2, reinterpret_cast<uint8_t *>(ptr), len,
                    HAL_MAX_DELAY);
  return len;
}
