
#pragma once

struct settings
{
	byte _brightness = 3;
	uint16_t _color[5] = { 0 };
	bool _rad = false;
	__uint8_t _base = 0;

};

extern settings _settings;