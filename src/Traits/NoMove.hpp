#pragma once

namespace Traits {

/**
 * @brief By inheriting this class, you will remove moving functionality from your class
 * 
 */
class NoMove {
 public:
    NoMove() {}
    NoMove(NoMove&&) = delete;
    NoMove& operator=(NoMove&&) = delete;
};
}  // namespace Traits
