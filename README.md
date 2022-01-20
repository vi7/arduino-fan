PC fan RPM monitoring with Arduino
==================================

This is the example code to monitor computer fan RPM (revolutions per minute) with Arduino

Different fans might have different dividers for the tacho pulse output. For example [Noctua NF-S12B redux-1200 PWM](https://noctua.at/en/nf-s12b-redux-1200-pwm) divider equals 2, for details see its [specification white paper](https://noctua.at/media/wysiwyg/Noctua_PWM_specifications_white_paper.pdf)

Vairous dividers in the code are defined via struct:
```cpp
fanspec fanspace[3]={{0,1},{1,2},{2,8}};
```

IDE: VSCode + PlatformIO

Possible improvements
---------------------

Replace `sei()`, `cli()` and `delay()` with attaching/detaching RPM interrupt on timer
