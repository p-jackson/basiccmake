#include "demo_b.h"

#include "hello.h"

#include <boost/filesystem.hpp>
#include <iostream>

std::string run() {
   auto greeting = hello::greeting("p-jackson");
   greeting += "\n\n";
   greeting += boost::filesystem::current_path().string();

   return greeting;
}
