#include "fibonacci.h"

#include <string>
#include <iostream>
#include <stdio.h>

#include "ic_api.h"

void fibonacci() {
  IC_API ic_api(CanisterQuery{std::string(__func__)}, false);

  // Get n from the wire
  uint32_t n{0};
  ic_api.from_wire(CandidTypeNat32{&n});

  // Compute the Fibonacci number
  uint32_t result{0};
  if (n == 0) {
    result = 0;
  } else if (n == 1) {
    result = 1;
  } else {
    std::uint32_t a = 0;
    std::uint32_t b = 1;
    for ( uint32_t i = 2; i <= n; ++i) {
      result = a + b;
      a = b;
      b = result;
    }
  }

  std::cout << "f(" << std::to_string(n) << ") = " << std::to_string(result) << std::endl;

  // Sends the result back over the wire, in Candid format
  ic_api.to_wire(CandidTypeNat32{result});
}