#pragma once


namespace woah {

enum class CWOAH {
    ON, CLOSE, OFF
};

class Runtime {
private:
    CWOAH state = CWOAH::OFF;

public:
    void Initialize();
    CWOAH GetState();

    bool ShouldClose();
    void SignalClose();

};

class IRuntime {
private:
    static Runtime* rt;

public:
    bool ShouldClose();
    void SignalClose();

};


}

