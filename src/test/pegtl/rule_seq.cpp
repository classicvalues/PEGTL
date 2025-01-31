// Copyright (c) 2014-2022 Dr. Colin Hirsch and Daniel Frey
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)

#include "test.hpp"

#include "verify_meta.hpp"
#include "verify_seqs.hpp"

namespace tao::pegtl
{
   void unit_test()
   {
      verify_meta< seq<>, internal::success >();
      verify_meta< seq< alpha >, internal::seq< alpha >, alpha >();
      verify_meta< seq< alpha, digit >, internal::seq< alpha, digit >, alpha, digit >();

      verify_seqs< seq >();
   }

}  // namespace tao::pegtl

#include "main.hpp"
