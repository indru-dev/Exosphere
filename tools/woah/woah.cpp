#include "woah.hpp"

using namespace woah;

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
    return IRuntime::rt->ShouldClose();
}

void IRuntime::SignalClose() {
    IRuntime::rt->SignalClose();
}

