#include "BlueMagicState.h"

BlueMagicState *BlueMagicState::instance = 0;

BlueMagicState *BlueMagicState::getInstance()
{
    if (instance == 0)
    {
        instance = new BlueMagicState();
    }

    return instance;
}

BlueMagicState::BlueMagicState()
{
}

void BlueMagicState::setChanged(bool changed)
{
    _changed = changed;
}

void BlueMagicState::setwbChanged(bool changed)
{
    _wbchanged = changed;
}

void BlueMagicState::settintChanged(bool changed)
{
    _tintchanged = changed;
}

void BlueMagicState::setisoChanged(bool changed)
{
    _isochanged = changed;
}

void BlueMagicState::setshutterChanged(bool changed)
{
    _shutterchanged = changed;
}

void BlueMagicState::setzoomChanged(bool changed)
{
    _zoomchanged = changed;
}

void BlueMagicState::setfocusChanged(bool changed)
{
    _focuschanged = changed;
}

void BlueMagicState::setapertureChanged(bool changed)
{
    _aperturechanged = changed;
}

bool BlueMagicState::changed()
{
    bool changed = _changed;
    _changed = false;
    return changed;
}

bool BlueMagicState::wbchanged()
{
    bool changed = _wbchanged;
    _wbchanged = false;
    return changed;
}

bool BlueMagicState::tintchanged()
{
    bool changed = _tintchanged;
    _tintchanged = false;
    return changed;
}

bool BlueMagicState::isochanged()
{
    bool changed = _isochanged;
    _isochanged = false;
    return changed;
}

bool BlueMagicState::shutterchanged()
{
    bool changed = _shutterchanged;
    _shutterchanged = false;
    return changed;
}

bool BlueMagicState::zoomchanged()
{
    bool changed = _zoomchanged;
    _zoomchanged = false;
    return changed;
}

bool BlueMagicState::focuschanged()
{
    bool changed = _focuschanged;
    _focuschanged = false;
    return changed;
}

bool BlueMagicState::aperturechanged()
{
    bool changed = _aperturechanged;
    _aperturechanged = false;
    return changed;
}

void BlueMagicState::settingsNotify(bool changed, uint8_t *data)
{
    _settingsChanged = changed;
    _settingsData = data;
}

bool BlueMagicState::settingsChanged()
{
    bool changed = _settingsChanged;
    _settingsChanged = false;
    return changed;
}

uint8_t *BlueMagicState::settingsData()
{
    return _settingsData;
}

void BlueMagicState::timecodeNotify(bool changed, uint8_t *data)
{
    _timecodeChanged = changed;
    _timecodeData = data;
}

bool BlueMagicState::timecodeChanged()
{
    bool changed = _timecodeChanged;
    _timecodeChanged = false;
    return changed;
}

uint8_t *BlueMagicState::timecodeData()
{
    return _timecodeData;
}

void BlueMagicState::statusNotify(bool changed, uint8_t *data)
{
    _statusChanged = changed;
    _statusData = data;
}

bool BlueMagicState::statusChanged()
{
    bool changed = _statusChanged;
    _statusChanged = false;
    return changed;
}

uint8_t *BlueMagicState::statusData()
{
    return _statusData;
}

void BlueMagicState::setCameraStatus(uint8_t status)
{
    _status = status;
}

uint8_t BlueMagicState::getCameraStatus()
{
    return _status;
}

void BlueMagicState::setTimecode(uint8_t H, uint8_t M, uint8_t S, uint8_t f)
{
    char timecode[12] = "00:00:00:00";
    char timecodeR[10] = "00000000";
    sprintf(timecode, "%02d:%02d:%02d:%02d", H, M, S, f);
    sprintf(timecodeR, "%02d%02d%02d%02d", H, M, S, f);
    _timecode = String(timecode);
    _timecodeRaw = String(timecodeR).toInt();
}

String BlueMagicState::getTimecode()
{
    return _timecode;
}

uint32_t BlueMagicState::getTimecodeRaw()
{
    return _timecodeRaw;
}

void BlueMagicState::setTransportMode(int8_t mode)
{
    _transportMode = mode;
}

int8_t BlueMagicState::getTransportMode()
{
    return _transportMode;
}

void BlueMagicState::setAperture(float aperture)
{
    _aperture = aperture;
}

float BlueMagicState::getAperture()
{
    return _aperture;
}

void BlueMagicState::setFocus(float focus)
{
    _focus = focus;
}

float BlueMagicState::getFocus()
{
    return _focus;
}

void BlueMagicState::setZoom(int16_t zoom)
{
    _zoom = zoom;
}

int16_t BlueMagicState::getZoom()
{
    return _zoom;
}

void BlueMagicState::setIso(uint32_t iso)
{
    _iso = iso;
}

int32_t BlueMagicState::getIso()
{
    return _iso;
}

void BlueMagicState::setShutter(int32_t shutter)
{
    _shutter = shutter;
}

float BlueMagicState::getShutter()
{
    return _shutter;
}

void BlueMagicState::setCodec(int8_t codec)
{
    _codec = codec;
}

int8_t BlueMagicState::getCodec()
{
    return _codec;
}

void BlueMagicState::setQuality(int8_t quality)
{
    _quality = quality;
}

int8_t BlueMagicState::getQuality()
{
    return _quality;
}

void BlueMagicState::setFrameRate(int16_t frameRate)
{
    _frameRate = frameRate;
}

int16_t BlueMagicState::getFrameRate()
{
    return _frameRate;
}

void BlueMagicState::setSensorFrameRate(int16_t sensorFrameRate)
{
    _sensorFrameRate = sensorFrameRate;
}

int16_t BlueMagicState::getSensorFrameRate()
{
    return _sensorFrameRate;
}

void BlueMagicState::setFrameWidth(int16_t width)
{
    _frameWidth = width;
}

int16_t BlueMagicState::getFrameWidth()
{
    return _frameWidth;
}

void BlueMagicState::setFrameHeight(int16_t height)
{
    _frameHeight = height;
}

int16_t BlueMagicState::getFrameHeight()
{
    return _frameHeight;
}

void BlueMagicState::setFormatFlags(int8_t flags)
{
    _flags = flags;
}

int8_t BlueMagicState::getFormatFlags()
{
    return _flags;
}

void BlueMagicState::setWhiteBalance(int16_t whiteBalance)
{
    _whiteBalance = whiteBalance;
}

int16_t BlueMagicState::getWhiteBalance()
{
    return _whiteBalance;
}

void BlueMagicState::setTint(int16_t tint)
{
    _tint = tint;
}

int16_t BlueMagicState::getTint()
{
    return _tint;
}
