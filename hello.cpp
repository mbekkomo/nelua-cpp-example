#include <iostream>
#include <sstream>

#include <cstring>
#include <cstdlib>
#include <cassert>

#define C extern "C"

class Hello {
    public:
        std::string toSomeone(std::string);
};

std::string Hello::toSomeone(std::string name) {
    std::stringstream output;
    output << "Hello " << name << "!\n";

    std::cout << output.str();
    return output.str();
}

C Hello* newHello() {
    return new Hello;
}

static char* local_strdup(const char* in) {
    assert(in != NULL);
    char *out = static_cast<char*>(malloc(1 + strlen(in)));
    return strcpy(out, in);
}

C const char* helloToSomeone(Hello* self, const char* name) {
    return (const char*) local_strdup(self->toSomeone(name).c_str());
}

C void gcHello(Hello* self) {
    delete self;
}
