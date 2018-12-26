#pragma once

namespace Traits {
class NoMove {
 public:
    NoMove() {}
    NoMove(NoMove&&) = delete;
    NoMove& operator=(NoMove&&) = delete;
};
}  // namespace Traits
