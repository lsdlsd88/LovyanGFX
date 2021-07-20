/*----------------------------------------------------------------------------/
  Lovyan GFX - Graphics library for embedded devices.

Original Source:
 https://github.com/lovyan03/LovyanGFX/

Licence:
 [FreeBSD](https://github.com/lovyan03/LovyanGFX/blob/master/license.txt)

Author:
 [lovyan03](https://twitter.com/lovyan03)

Contributors:
 [ciniml](https://github.com/ciniml)
 [mongonta0716](https://github.com/mongonta0716)
 [tobozo](https://github.com/tobozo)
/----------------------------------------------------------------------------*/
#pragma once

#include "misc/colortype.hpp"
#include "misc/enum.hpp"

namespace lgfx
{
 inline namespace v1
 {
//----------------------------------------------------------------------------

  class LovyanGFX;

  class LGFX_Button  
  {
  public:
    template<typename T>
    void initButton( LovyanGFX *gfx, std::int16_t x, std::int16_t y, std::uint16_t w, std::uint16_t h
                   , const T& outline, const T& fill, const T& textcolor, const char *label, float textsize_x = 1.0f, float textsize_y = 0.0f)
    {
      _outlinecolor = lgfx::convert_to_rgb888(outline);
      _fillcolor    = lgfx::convert_to_rgb888(fill);
      _textcolor    = lgfx::convert_to_rgb888(textcolor);
      _init_button(gfx, x-(w>>1), y-(h>>1), w, h, label, textsize_x, textsize_y);
    }

    template<typename T>
    void initButtonUL( LovyanGFX *gfx, std::int16_t x, std::int16_t y, std::uint16_t w, std::uint16_t h
                     , const T& outline, const T& fill, const T& textcolor, const char *label, float textsize_x = 1.0f, float textsize_y = 0.0f)
    {
      _outlinecolor = lgfx::convert_to_rgb888(outline);
      _fillcolor    = lgfx::convert_to_rgb888(fill);
      _textcolor    = lgfx::convert_to_rgb888(textcolor);
      _init_button(gfx, x, y, w, h, label, textsize_x, textsize_y);
    }

    void setLabelDatum(std::int16_t x_delta, std::int16_t y_delta, textdatum_t datum = middle_center);

    void drawButton(bool inverted = false, const char* long_name = nullptr);

    bool contains(std::int16_t x, std::int16_t y) const
    {
      return (std::uint_fast16_t)(x - _x) < _w && (std::uint_fast16_t)(y - _y) < _h;
    }

    void press(bool p)
    {
      _last_press = _pressed;
      _pressed = p;
    }
    bool isPressed(void) const { return _pressed; }
    bool justPressed(void) const { return (_pressed && !_last_press); }
    bool justReleased(void) const { return (!_pressed && _last_press); }

  private:
    void _init_button( LovyanGFX *gfx, std::int16_t x, std::int16_t y, std::uint16_t w, std::uint16_t h
                     , const char *label, float textsize_x, float textsize_y);

    LovyanGFX *_gfx = nullptr;
    std::int16_t  _x = 0; // Coordinates of top-left corner of button
    std::int16_t  _y = 0; // Coordinates of top-left corner of button
    std::int16_t  _xd = 0; // Button text datum offsets (wrt centre of button)
    std::int16_t  _yd = 0; // Button text datum offsets (wrt centre of button)
    std::uint16_t _w = 0;   // Width and height of button
    std::uint16_t _h = 0;   // Width and height of button
    std::uint32_t _outlinecolor = 0xFFFFFF;
    std::uint32_t _fillcolor    = 0;
    std::uint32_t _textcolor    = 0xFFFFFF;
    textdatum_t _textdatum = middle_center; // Text size multiplier and text datum for button
    char _label[12]; // Button text is 11 chars maximum unless long_name used
    float _textsize_x, _textsize_y;
    bool _pressed, _last_press; // Button states
  };

//----------------------------------------------------------------------------
 }
}

using LGFX_Button = lgfx::LGFX_Button;
