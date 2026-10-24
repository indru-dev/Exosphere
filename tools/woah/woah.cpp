#include "woah.hpp"

using namespace woah;

Runtime* current;

void Runtime::Initialize() {
    if(state == CWOAH::OFF) state = CWOAH::ON;
}

CWOAH Runtime::GetState() {
    return state;
}

bool Runtime::ShouldClose() {
    if(state == CWOAH::CLOSE) {
        state = CWOAH::OFF;
        return true;
    } return false;
}

void Runtime::SignalClose() {
    state = CWOAH::CLOSE;
}

bool IRuntime::ShouldClose() {
    return current->ShouldClose();
}

void IRuntime::SignalClose() {
    current->SignalClose();
}

void AssignCurrentRuntime(Runtime& rt) {
    current = &rt;
}

