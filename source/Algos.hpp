#ifndef ALGOS_HPP_
#define ALGOS_HPP_

// Copyright (c) 2014, Ruslan Baratov
// All rights reserved.

#include "cppx.hpp"
#include "format.h"
#include <boost/spirit/include/karma.hpp>
#include "alexandrescu.hpp"

class AlgoFmtFormat {
 public:
  template <class Vector>
  static void run(char* buffer, const Vector& in) {
    for(auto& i: in) {
      fmt::FormatDec(buffer, i);
    }
    *buffer = '\0';
  }
};

class AlgoCppx {
 public:
  template <class Vector>
  static void run(char* buffer, const Vector& in) {
    for(auto& i: in) {
      cppx::decimal_from(i, buffer);
      buffer += strlen(buffer);
    }
  }
};

class AlgoBoostKarma {
 public:
  template <class Vector>
  static void run(char* buffer, const Vector& in) {
    for(auto& i: in) {
      using namespace boost::spirit;
      karma::generate(buffer, int_, i);
    }
    *buffer = '\0';
  }
};

class AlgoAlexandrescu {
 public:
  template <class Vector>
  static void run(char* buffer, const Vector& in) {
    for(auto& i: in) {
      alexandrescu::generate(buffer, i);
    }
    *buffer = '\0';
  }
};

#endif // ALGOS_HPP_
