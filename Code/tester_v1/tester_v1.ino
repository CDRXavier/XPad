#include <XInput.h>

const int8_t NumButtons = 10;
const int8_t Buttons[NumButtons] = {
  BUTTON_A,
  BUTTON_B,
  BUTTON_X,
  BUTTON_Y,
  BUTTON_LB,
  BUTTON_RB,
  BUTTON_BACK,
  BUTTON_START,
  BUTTON_L3,
  BUTTON_R3,
};


short choice;
short choicer;
bool indec;
bool rep;


uint8_t DpadSta;

uint8_t DpadBtnU;
uint8_t DpadBtnD;
uint8_t DpadBtnL;
uint8_t DpadBtnR;

//int16_t TrigLMax;
//int16_t TrigRMax;

enum class StateMode : uint8_t {DpadIn, StkLR, ShdBtn, TrgBtn, TrgAdd};


void setup() {


  XpandShield::Startup();
  XpandShield::setFrameDiff(100);


  DpadBtnX = 0;
  DpadBtnY = 0;
  XInput.setAutoSend(false);
  XInput.begin();
}

void loop() {



  if (XpandShield::nextFrame()) {
    XpandShield::pollButtons();
    switch (activeMode)
    case StateMode::DPadIn:
    {

      DpadBtnX = 0;
      DpadBtnY = 0;
      if (XpandShield::pressed(XpandShield::UP_BUTTON))
        ++DpadBtnX;
      if (XpandShield::pressed(XpandShield::DOWN_BUTTON))
        --DpadBtnX;
      if (XpandShield::pressed(XpandShield::RIGHT_BUTTON))
        ++DpadBtnY;
      if (XpandShield::pressed(XpandShield::LEFT_BUTTON))
        --DpadBtnY;

      XInput.setDpad(DpadBtnX == 1, DpadBtnY == -1, DPadBtnX == -1, DpadBtnY == 1);


      XpandShield::clearDisplay();
      XpandShield::drawPixel(0, 0, XpandShield::WHITE);
      XpandShield::drawPixel(127, 63, XpandShield::WHITE);

      XpandShield::drawRect(0, 0, 64, 10, XpandShield::WHITE);

      XpandShield::setCursor(0, 12);
      XpandShield::print("t\0", XpandShield::WHITE);
      XpandShield::setCursor(18, 12);
      XpandShield::print("dpad\0", XpandShield::WHITE);
      XpandShield::write('.', XpandShield::WHITE);
      XpandShield::print("test\0", XpandShield::WHITE);
      XpandShield::setCursor(52, 12);
      if (XpandShield::pressed(XpandShield::UP_BUTTON))
        XpandShield::print("up\0", XpandShield::WHITE);
      if (XpandShield::pressed(XpandShield::DOWN_BUTTON))
        XpandShield::print("down\0", XpandShield::WHITE);
      XpandShield::setCursor(80, 12);
      if (XpandShield::pressed(XpandShield::RIGHT_BUTTON))
        XpandShield::print("left\0", XpandShield::WHITE);
      XpandShield::setCursor(102, 12);
      if (XpandShield::pressed(XpandShield::RIGHT_BUTTON))
        XpandShield::print("right\0", XpandShield::WHITE);
      XpandShield::display();

      if (XpandShield::pressed(XpandShield::A_BUTTON))
        activeMode = StateMode::StkLR;
      if (XpandShield::pressed(XpandShield::B_BUTTON))
        activeMode = StateMode::TrigBtn;

    }
  case StateMode::TrgBtn:
    {

      XpandShield::clearDisplay();
      XpandShield::drawPixel(0, 0, XpandShield::WHITE);
      XpandShield::drawPixel(127, 63, XpandShield::WHITE);

      XpandShield::drawRect(0, 0, 64, 10, XpandShield::WHITE);

      XpandShield::setCursor(0, 12);
      XpandShield::print("t\0", XpandShield::WHITE);
      XpandShield::setCursor(18, 12);
      XpandShield::print("dpad\0", XpandShield::WHITE);
      XpandShield::write('.', XpandShield::WHITE);
      XpandShield::print("test\0", XpandShield::WHITE);
      XpandShield::setCursor(52, 12);
      if (XpandShield::pressed(XpandShield::UP_BUTTON))
        XpandShield::print("up\0", XpandShield::WHITE);
      if (XpandShield::pressed(XpandShield::DOWN_BUTTON))
        XpandShield::print("down\0", XpandShield::WHITE);
      XpandShield::setCursor(80, 12);
      if (XpandShield::pressed(XpandShield::RIGHT_BUTTON))
        XpandShield::print("left\0", XpandShield::WHITE);
      XpandShield::setCursor(102, 12);
      if (XpandShield::pressed(XpandShield::RIGHT_BUTTON))
        XpandShield::print("right\0", XpandShield::WHITE);
      XpandShield::display();

      if (XpandShield::pressed(XpandShield::UP_BUTTON))
        XInput.press(BUTTON_A);
      if (XpandShield::release(XpandShield::UP_BUTTON))
        XInput.release(BUTTON_A);
      if (XpandShield::pressed(XpandShield::DOWN_BUTTON))
        XInput.press(BUTTON_X);
      if (XpandShield::release(XpandShield::UP_BUTTON))
        XInput.release(BUTTON_X);
      if (XpandShield::pressed(XpandShield::RIGHT_BUTTON))
        XInput.press(BUTTON_B);
      if (XpandShield::release(XpandShield::UP_BUTTON))
        XInput.release(BUTTON_B);
      if (XpandShield::pressed(XpandShield::LEFT_BUTTON))
        XInput.press(BUTTON_Y);
      if (XpandShield::release(XpandShield::UP_BUTTON))
        XInput.release(BUTTON_Y);


      if (XpandShield::justPressed(XpandShield::A_BUTTON))
        activeMode = StateMode::DpadIn;
      if (XpandShield::justPressed(XpandShield::B_BUTTON))
        activeMode = StateMode::ShdBtn;

    }
  case StateMode::ShdBtn:
    {

      XpandShield::clearDisplay();
      XpandShield::drawPixel(0, 0, XpandShield::WHITE);
      XpandShield::drawPixel(127, 63, XpandShield::WHITE);

      XpandShield::drawRect(0, 0, 64, 10, XpandShield::WHITE);

      XpandShield::setCursor(0, 12);
      XpandShield::print("t\0", XpandShield::WHITE);
      XpandShield::setCursor(18, 12);
      XpandShield::print("dpad\0", XpandShield::WHITE);
      XpandShield::write('.', XpandShield::WHITE);
      XpandShield::print("test\0", XpandShield::WHITE);
      XpandShield::setCursor(52, 12);
      if (XpandShield::pressed(XpandShield::UP_BUTTON))
        XpandShield::print("up\0", XpandShield::WHITE);
      if (XpandShield::pressed(XpandShield::DOWN_BUTTON))
        XpandShield::print("down\0", XpandShield::WHITE);
      XpandShield::setCursor(80, 12);
      if (XpandShield::pressed(XpandShield::RIGHT_BUTTON))
        XpandShield::print("left\0", XpandShield::WHITE);
      XpandShield::setCursor(102, 12);
      if (XpandShield::pressed(XpandShield::RIGHT_BUTTON))
        XpandShield::print("right\0", XpandShield::WHITE);
      XpandShield::display();

      if (XpandShield::pressed(XpandShield::UP_BUTTON))
        XInput.press(BUTTON_START);
      if (XpandShield::release(XpandShield::UP_BUTTON))
        XInput.release(BUTTON_START);
      if (XpandShield::pressed(XpandShield::DOWN_BUTTON))
        XInput.press(BUTTON_BACK);
      if (XpandShield::release(XpandShield::DOWN_BUTTON))
        XInput.release(BUTTON_BACK);
      if (XpandShield::pressed(XpandShield::RIGHT_BUTTON))
        XInput.press(BUTTON_RB);
      if (XpandShield::release(XpandShield::RIGHT_BUTTON))
        XInput.release(BUTTON_RB);
      if (XpandShield::pressed(XpandShield::LEFT_BUTTON))
        XInput.press(BUTTON_LB);
      if (XpandShield::release(XpandShield::LEFT_BUTTON))
        XInput.release(BUTTON_LB);


      if (XpandShield::justPressed(XpandShield::A_BUTTON))
        activeMode = StateMode::TrgBtn;
      if (XpandShield::justPressed(XpandShield::B_BUTTON))
        activeMode = StateMode::TrgAdd;

    }
  case StateMode::TrgAdd: {


      XpandShield::clearDisplay();
      XpandShield::drawPixel(0, 0, XpandShield::WHITE);
      XpandShield::drawPixel(127, 63, XpandShield::WHITE);

      XpandShield::drawRect(0, 0, 64, 10, XpandShield::WHITE);

      XpandShield::setCursor(0, 12);
      XpandShield::print("tas\0", XpandShield::WHITE);
      XpandShield::setCursor(18, 12);
      XpandShield::print("trig\0", XpandShield::WHITE);
      XpandShield::write('.', XpandShield::WHITE);
      XpandShield::print("test\0", XpandShield::WHITE);
      XpandShield::setCursor(23, 34);
      if (XpandShield::pressed(XpandShield::UP_BUTTON))
        XpandShield::print("up\0", XpandShield::WHITE);
      if (XpandShield::pressed(XpandShield::DOWN_BUTTON))
        XpandShield::print("down\0", XpandShield::WHITE);
      XpandShield::setCursor(75, 24);
      if (XpandShield::pressed(XpandShield::RIGHT_BUTTON))
        XpandShield::print("left\0", XpandShield::WHITE);
      XpandShield::setCursor(16, 87);
      if (XpandShield::pressed(XpandShield::RIGHT_BUTTON))
        XpandShield::print("right\0", XpandShield::WHITE);
      XpandShield::display();



      if (XpandShield::pressed(XpandShield::RIGHT_BUTTON))
        XInput.press(BUTTON_RB);
      if (XpandShield::release(XpandShield::RIGHT_BUTTON))
        XInput.release(BUTTON_RB);
      if (XpandShield::pressed(XpandShield::LEFT_BUTTON))
        XInput.press(BUTTON_LB);
      if (XpandShield::release(XpandShield::LEFT_BUTTON))
        XInput.release(BUTTON_LB);

      if (XpandShield::pressed(XpandShield::UP_BUTTON))
        XInput.setTrigger(TRIGGER_LEFT, 255);
      if (XpandShield::release(XpandShield::UP_BUTTON))
        XInput.setTrigger(TRIGGER_LEFT, 0);
      if (XpandShield::pressed(XpandShield::DOWN_BUTTON))
        XInput.setTrigger(TRIGGER_RIGHT, 255);
      if (XpandShield::release(XpandShield::DOWN_BUTTON))
        XInput.setTrigger(TRIGGER_RIGHT, 0);


      if (XpandShield::justPressed(XpandShield::A_BUTTON))
        activeMode = StateMode::ShdBtn;
      if (XpandShield::justPressed(XpandShield::B_BUTTON))
        activeMode = StateMode::StkLR;
    }

  case StateMode::StkLR: {
      XpandShield::clearDisplay();

      XpandShield::setCursor(9, 7);
      XpandShield::print("stk\0", XpandShield::WHITE);
      XpandShield::setCursor(8, 54);
      XpandShield::print("LR\0", XpandShield::WHITE);
      XpandShield::write('.', XpandShield::WHITE);
      XpandShield::print("test\0", XpandShield::WHITE);
      XpandShield::setCursor(10, 46);
      if (XpandShield::pressed(XpandShield::UP_BUTTON))
        XpandShield::print("up\0", XpandShield::WHITE);
      if (XpandShield::pressed(XpandShield::DOWN_BUTTON))
        XpandShield::print("down\0", XpandShield::WHITE);
      XpandShield::setCursor(68, 7);
      if (XpandShield::pressed(XpandShield::RIGHT_BUTTON))
        XpandShield::print("left\0", XpandShield::WHITE);
      XpandShield::setCursor(35, 47);
      if (XpandShield::pressed(XpandShield::RIGHT_BUTTON))
        XpandShield::print("right\0", XpandShield::WHITE);
      XpandShield::display();



      DpadBtnX = 0;
      DpadBtnY = 0;
      if (XpandShield::pressed(XpandShield::UP_BUTTON))
        ++DpadBtnX;
      if (XpandShield::pressed(XpandShield::DOWN_BUTTON))
        --DpadBtnX;
      if (XpandShield::pressed(XpandShield::RIGHT_BUTTON))
        ++DpadBtnY;
      if (XpandShield::pressed(XpandShield::LEFT_BUTTON))
        --DpadBtnY;


      XInput.setJoystick(JOY_LEFT, DpadBtnX > 0 ? 1024 : DpadBtnX < -1024 ? 0, DpadBtnY > 0 ? 1024 : DpadBtnY < -1024 ? 0);
      XInput.setJoystick(JOY_RIGHT, DpadBtnX > 0 ? -1024 : DpadBtnX < 1024 ? 0, DpadBtnY > 0 ? 1024 : DpadBtnY < -1024 ? 0);

      if (XpandShield::justPressed(XpandShield::A_BUTTON))
        activeMode = StateMode::TrgAdd;
      if (XpandShield::justPressed(XpandShield::B_BUTTON))
        activeMode = StateMode::DpadIn;
    }
  }

  // Send values to PC
  XInput.send();
}
