// Copyright (c) 2016-2017 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#ifndef PEGTL_INTERNAL_ISTREAM_READER_HH
#define PEGTL_INTERNAL_ISTREAM_READER_HH

#include <istream>

#include "../config.hh"
#include "../input_error.hh"

namespace PEGTL_NAMESPACE
{
   namespace internal
   {
      struct istream_reader
      {
         explicit
         istream_reader( std::istream & s )
               : m_istream( s )
         { }

         std::size_t operator() ( char * buffer, const std::size_t length )
         {
            m_istream.read( buffer, std::streamsize( length ) );

            if ( const auto r = m_istream.gcount() ) {
               return std::size_t( r );
            }
            if ( m_istream.eof() ) {
               return 0;
            }
            PEGTL_THROW_INPUT_ERROR( "error in istream.read()" );
         }

         std::istream & m_istream;
      };

   } // namespace internal

} // namespace PEGTL_NAMESPACE

#endif
