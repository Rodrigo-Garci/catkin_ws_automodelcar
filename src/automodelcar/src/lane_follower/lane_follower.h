/* Global Parameters initialization */
static const std::string LANE_DETECTION_WINDOW = "Lane Follower";
bool DEBUG = false;
int MAX_STEERING_ANGLE_LEFT = 10;
int MAX_STEERING_ANGLE_RIGHT = 170;
int MAX_VEL = -400;
int SERVO_STEP = 3;
int LANE_WIDTH = 110;
int SERVO_CENTER = 90;
bool DRIVE_RIGHT_LANE = true;
float STEERING_SPEED_RATIO = 1.2;

int const SPEED_INCREASE_STEP = 8;
int const SPEED_DECREASE_STEP = 10;
float const MULTIPLY_FACTOR = MAX_VEL / 100.0;

 /*
  * Calculates the servo PWM accordingly to the center_deviation,
  * the curvature degree and the last center deviation using a PD
  * control.
  */
int CalculateServoPWM(
    int curvature_degree,
    int center_deviation, 
    int last_center_deviation) 
{
    float pe;
    float pp;
    int output;  
          
    if (curvature_degree > 100 || curvature_degree<80)
    {
        pp = 0.88;
        pe = 1.25;
    }
    else    
    {
        pe = 0.3;
        pp = 1.02;
    }

          
    output = 
        center_deviation * pe + 
        curvature_degree * pp + 
        (center_deviation - last_center_deviation) * 1.35;
    
    return output;
}

 /*
  * Saturates the servo PWM value accordingly to the 
  * servo limits.
  */
int ServoSaturation(
    int calculated_servo_PWM,
    int current_steering_PWM)
{

    if (calculated_servo_PWM > current_steering_PWM + SERVO_STEP)
    {
        current_steering_PWM += SERVO_STEP;
    }
    else if (calculated_servo_PWM < current_steering_PWM - SERVO_STEP)
    {
        current_steering_PWM -= SERVO_STEP;
    }

    if (current_steering_PWM > MAX_STEERING_ANGLE_RIGHT)
    {
        current_steering_PWM = MAX_STEERING_ANGLE_RIGHT;
    }
    else if (current_steering_PWM < MAX_STEERING_ANGLE_LEFT)
    {
        current_steering_PWM = MAX_STEERING_ANGLE_LEFT;
    }
    

    return current_steering_PWM;
}

/*
  * Calculates the speed PWM value accordingly to the 
  * steering values.
  */
  int CalculateSpeedPWM(
    int current_steering_PWM)
  {
    float tmp;
    int calculated_PWM;

    // Calculate the PWM speed value (lineal function) 
    tmp = 
        abs((SERVO_CENTER - current_steering_PWM) * MULTIPLY_FACTOR);

    calculated_PWM = int(STEERING_SPEED_RATIO * tmp) + MAX_VEL;
  
    return calculated_PWM;
  }

  int SpeedSaturation(
      int calcualted_speed,
      int current_speed)
  {
    if (calcualted_speed > current_speed)
    {
        current_speed += SPEED_DECREASE_STEP;
    }
    else if (calcualted_speed < current_speed)
    {
        current_speed -= SPEED_INCREASE_STEP;
    }

    return current_speed;
  }