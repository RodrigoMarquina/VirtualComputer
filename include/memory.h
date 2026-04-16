#pragma once

#include <array>

bool SRLatch(bool s, bool r, bool q);

std::array<bool, 8> Register(std::array<bool, 8> d, bool we, bool reset, std::array<bool, 8> q);