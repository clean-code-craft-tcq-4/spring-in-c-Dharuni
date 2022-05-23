
#include "alert.h"
#include "stats.h"
#include "stdio.h"
#include "stdlib.h"

void emailAlerter(void)
{
  emailAlertCallCount++;
}

void ledAlerter(void)
{
  ledAlertCallCount++;
}

