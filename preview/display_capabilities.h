#ifndef DISPLAY_CAPABILITIES_H
#define DISPLAY_CAPABILITIES_H

class QWindow;

struct DisplayCapabilities
{
    bool known = false;
    bool hdrActive = false;
    int bitsPerColor = 8;
};

// What the monitor showing a_pWindow is driven with; known stays false where the platform gives no answer.
DisplayCapabilities displayCapabilities(QWindow* a_pWindow);

#endif  // DISPLAY_CAPABILITIES_H
