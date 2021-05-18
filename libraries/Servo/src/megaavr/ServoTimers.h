#ifndef __SERVO_TIMERS_H__
#define __SERVO_TIMERS_H__

#if defined(TCB1) && (!defined(MILLIS_USE_TIMERB1))
  #define USE_TIMERB1
#else
  #define USE_TIMERB0
#endif

#if (!defined(USE_TIMERB1) && !defined(USE_TIMERB2) && !defined(USE_TIMERB0))||(defined(USE_TIMERB0)&&defined(MILLIS_USE_TIMERB0))
  # error "No timer available for servo, only option used for millis()"
#endif
static volatile TCB_t *_timer =
#if defined(USE_TIMERB0)
  &TCB0;
#endif
#if defined(USE_TIMERB1)
  &TCB1;
#endif
#if defined(USE_TIMERB2)
  &TCB2;
#endif

typedef enum {
  timer0,
  _Nbr_16timers
} timer16_Sequence_t;


#endif  /* __SERVO_TIMERS_H__ */
