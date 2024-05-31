<div align="center">
    <img src="./images/squirrel.png">
</div>

This keymap has been made for the [Chew](https://github.com/flinguenheld/chew) keyboard.  
It works with both split and monobloc versions.  
It is inspired by [Ergo-L](https://ergol.org/) which is a French layout.  
Nonetheless it uses the [US international extended](https://github.com/qmk/qmk_firmware/blob/master/quantum/keymap_extras/keymap_us_extended.h) keymap for all French keys.  

It makes use of the _best_ [QMK](https://docs.qmk.fm/#/) features :
- combos ❤️
- auto shift
- leader key

<div align="center">
    <img src="https://github.com/flinguenheld/chew/raw/main/images/hazelnuts.png?raw=true">
</div>

### Install

Clone this repo in the folder :

    ~/qmk_firmware/keyboards/chew/keymaps/
    ~/qmk_firmware/keyboards/chew_mono/keymaps/

Move inside the folder and use this command :

    qmk compile && qmk flash

Finally press twice the *reset* button, the controller should appear in your file explorer.  

You can read the [Chew wiki](https://github.com/flinguenheld/chew/wiki) for more information.  

### Version

To select the version, open the *config.h* file and comment/uncomment these lines:

```
// #define SPLIT
// #define VBUS
```

<div align="center">
    <img src="https://github.com/flinguenheld/chew/raw/main/images/carrots.png?raw=true">
</div>

### Layouts

<div align="center">
    <img src="./images/layouts.png">
    <img src="https://github.com/flinguenheld/chew/raw/main/images/carrots.png?raw=true">
</div>

<div align="center">
    <img src="./images/combos.png">
    <img src="https://github.com/flinguenheld/chew/raw/main/images/hazelnuts.png?raw=true">
</div>

### Leader

| ------------------ | -------- | ------------------ | -------- | ------------------ | -------- |
| :----------------: | :------- | :----------------: | :------- | :----------------: | :------- |
|     C + O + P      | ©        |     M + U + L      | ×        |     L + O + V      | ♥        |
|     R + E + G      | ®        |     D + I + V      | ÷        |     F + L + A      | ⚡       |
|     D + I + A      | ø        |       P + M        | ±        |     S + T + A      | ✶        |
|     D + E + G      | °        |     I + N + E      | ≠        |     B + U + L      | 💡       |
|     S + E + C      | §        |     A + L + M      | ≈        |     I + N + F      | ℹ️        |
|     P + O + U      | £        |     S + Q + U      | √        |     G + E + A      | ⚙️        |
|     Y + E + N      | ¥        |     I + N + F      | ∞        |         V          | ✓        |
|     C + E + N      | ¢        |       < + <        | ≤        |       V + B        | ✔        |
|     B + E + T      | ß        |       > + >        | ≥        |       V + V        | ✅       |
|     M + I + C      | µ        |     F + C + T      | ¼        |         X          | ✗        |
|       P + I        | π        |     F + C + G      | ½        |       X + B        | ✘        |
|     O + M + E      | Ω        |     F + H + T      | ¾        |         ?          | ❔       |
|     U + P + F      | ⁰        |                    |          |       ? + ?        | ❓       |
|     D + N + F      | ₀        |                    |          |         !          | ❕       |
|                    |          |                    |          |       ! + !        | ❗       |
