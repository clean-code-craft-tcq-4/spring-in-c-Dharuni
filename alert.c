
#include "alert.h"
#include "stats.h"
#include "stdio.h"
#include "stdlib.h"

void emailAlerter(void)
{
  emailAlertCallCount = 1;
}

void ledAlerter(void)
{
  ledAlertCallCount = 1;
}

void check_and_alert(const float maxThreshold, alerter_funcptr alerters, Stats computedStats)
{
  if(computedStats.max > maxThreshold)
  {
    (void) (*alerters[0])();
    (void) (*alerters[1])();
  }
  else
  {
    emailAlertCallCount = 0;
    ledAlertCallCount = 0;
  }
}
