#include <SDL.h>

#ifndef _TIMER_H_
#define _TIMER_H_

class Timer {

        // Properties
    private:
        static Timer *s_Instance;
        double m_DeltaTime;
        Uint64 m_Now;
        Uint64 m_LastTime;

        // Constructors
    private:
        Timer();

    public:
        // Getters
        double GetDeltaTime();

        // Actions
        void Tick();


        static Timer *GetInstance() {
            return s_Instance = (s_Instance != nullptr) ? s_Instance : new Timer();
        }

};
#endif
