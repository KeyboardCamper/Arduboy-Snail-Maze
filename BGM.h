

const byte bootsound[] PROGMEM = {
// Sonic the Hedgehog - Title Screen
 3,232, 0x90,36, 0,125, 0x80, 0,125, 0x90,69, 0x91,38, 0,125, 0x80, 0x81, 0,125, 0x90,69, 0x91,38, 0,125, 0x80,
 0x81, 0,125, 0x90,69, 0x91,38, 0,125, 0x80, 0x81, 0,125, 0x90,45, 0x91,36, 0,125, 0x80, 0x81, 0,125, 0x90,73, 0x91,57,
 0x92,69, 0x93,38, 0,125, 0x81, 0x83, 0,125, 0x91,52, 0x93,36, 0,125, 0x93,36, 0x81, 0,125, 0x90,52, 0x91,73, 0x92,69,
 0x93,38, 0,125, 0x80, 0x83, 0,125, 0x90,55, 0x93,36, 0x91,74, 0x92,71, 0,125, 0x80, 0x83, 0,125, 0x93,38, 0x90,55,
 0,125, 0x90,69, 0x93,36, 0x91,73, 0x92,54, 0,125, 0x82, 0x83, 0,125, 0x93,36, 0x92,55, 0,125, 0x93,38, 0x92,54,
 0,125, 0x82, 0x83, 0,125, 0x93,36, 0x90,45, 0x91,69, 0x92,73, 0,125, 0x80, 0x81, 0x82, 0x83, 0,125, 0x90,57, 0x91,69,
 0x93,38, 0x92,73, 0,125, 0x80, 0x81, 0x82, 0x83, 0,125, 0x90,52, 0x91,69, 0x93,36, 0x92,73, 0,125, 0x93,36, 0x80, 0x81,
 0x82, 0,125, 0x90,69, 0x91,52, 0x92,64, 0x93,38, 0,125, 0x80, 0x81, 0x82, 0x83, 0,125, 0x90,67, 0x91,50, 0x92,62, 0x93,36,
 0,125, 0x81, 0x83, 0,125, 0x91,50, 0x93,38, 0,125, 0x90,71, 0x91,49, 0x92,67, 0x93,36, 0,125, 0x81, 0x83, 0,125,
 0x91,50, 0x93,36, 0,125, 0x91,49, 0x93,38, 0,125, 0x81, 0x83, 0,125, 0x90,45, 0x93,36, 0x91,69, 0x92,61, 0,125,
 0x80, 0x81, 0x82, 0x83, 0,125, 0x93,38, 0x90,73, 0x91,57, 0x92,69, 0,125, 0x80, 0x81, 0x82, 0x83, 0,125, 0x93,36, 0x90,81,
 0x91,52, 0x92,76, 0,125, 0x93,36, 0x80, 0x81, 0x82, 0,125, 0x90,76, 0x91,49, 0x92,69, 0x93,38, 0,125, 0x80, 0x81, 0x82,
 0x83, 0,125, 0x90,45, 0x93,36, 0,125, 0x91,80, 0x90,74, 0x92,56, 0x83, 0,125, 0x93,38, 0,125, 0x93,36, 0,125,
 0x90,81, 0x91,57, 0x92,73, 0x83, 0,125, 0x93,36, 0x80, 0x81, 0x82, 0,125, 0x90,81, 0x91,45, 0x92,57, 0x93,38, 0,125,
 0x80, 0,125, 0x90,81, 0,125, 0x80, 0,125, 0x90,81, 0,125, 0x80, 0,125, 0x90,81, 0,125, 0x80, 1,119, 0x81, 0x82,
 3,232, 0x83,
 0xf0
};
// This score contains 397 bytes, and 4 tone generators are used.

const byte bgm[] PROGMEM = {
// SMS BIOS - Snail Game
 0x90,69, 0x91,69, 0x92,57, 0x93,44, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,38, 0x90,76, 0x91,76, 0x92,69,
 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,44, 0x90,73, 0x91,73, 0x92,57, 0,66, 0x83, 0,66, 0x93,44, 0x80,
 0x81, 0x82, 0,66, 0x83, 0,66, 0x90,76, 0x91,76, 0x92,69, 0x93,38, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,44,
 0x90,74, 0x91,74, 0x92,62, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,38, 0x90,71, 0x91,71, 0x92,74, 0,66,
 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,44, 0x90,73, 0x91,73, 0x92,64, 0,66, 0x83, 0,66, 0x93,44, 0x80, 0x81, 0x82,
 0,66, 0x83, 0,66, 0x90,71, 0x91,71, 0x92,76, 0x93,38, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,44, 0x90,69,
 0x91,69, 0x92,57, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,38, 0x90,71, 0x91,71, 0x92,64, 0,66, 0x83, 0,66,
 0x80, 0x81, 0x82, 0,133, 0x93,44, 0x90,73, 0x91,73, 0x92,57, 0,66, 0x83, 0,66, 0x93,44, 0x80, 0x81, 0x82, 0,66, 0x83,
 0,66, 0x90,71, 0x91,71, 0x92,69, 0x93,38, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,44, 0x90,64, 0x91,64,
 0x92,52, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,38, 0x90,66, 0x91,66, 0x92,59, 0,66, 0x83, 0,66, 0x80,
 0x81, 0x82, 0,133, 0x93,44, 0x90,64, 0x91,64, 0x92,52, 0,66, 0x83, 0,66, 0x93,44, 0x80, 0x81, 0x82, 0,66, 0x83, 0,66,
 0x90,64, 0x93,38, 0,66, 0x83, 0,66, 0x80, 0,133, 0x93,44, 0x90,69, 0x91,69, 0x92,57, 0,66, 0x83, 0,66, 0x80,
 0x81, 0x82, 0,133, 0x93,38, 0x90,76, 0x91,76, 0x92,69, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,44, 0x90,73,
 0x91,73, 0x92,57, 0,66, 0x83, 0,66, 0x93,44, 0x80, 0x81, 0x82, 0,66, 0x83, 0,66, 0x90,76, 0x91,76, 0x92,69, 0x93,38,
 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,44, 0x90,74, 0x91,74, 0x92,62, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82,
 0,133, 0x93,38, 0x90,71, 0x91,71, 0x92,74, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,44, 0x90,73, 0x91,73,
 0x92,64, 0,66, 0x83, 0,66, 0x93,44, 0x80, 0x81, 0x82, 0,66, 0x83, 0,66, 0x90,71, 0x91,71, 0x92,76, 0x93,38, 0,66,
 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,44, 0x90,73, 0x91,73, 0x92,57, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133,
 0x93,38, 0x90,71, 0x91,71, 0,13, 0x92,62, 0,53, 0x83, 0,66, 0x80, 0x81, 0,13, 0x82, 0,120, 0x93,44, 0x90,69,
 0x91,69, 0x92,57, 0,66, 0x83, 0,66, 0x93,44, 0x80, 0x81, 0x82, 0,66, 0x83, 0,66, 0x90,68, 0x91,68, 0x92,64, 0x93,38,
 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,44, 0x90,69, 0x91,69, 0x92,57, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82,
 0,133, 0x93,38, 0x90,69, 0x91,69, 0x92,69, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,44, 0x90,69, 0x91,69,
 0x92,57, 0,66, 0x83, 0,66, 0x93,44, 0x80, 0x81, 0x82, 0,66, 0x83, 0,66, 0x93,38, 0,66, 0x83, 0,200, 0x90,69,
 0x91,69, 0x92,57, 0x93,44, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,38, 0x90,76, 0x91,76, 0x92,69, 0,66,
 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,44, 0x90,73, 0x91,73, 0x92,57, 0,66, 0x83, 0,66, 0x93,44, 0x80, 0x81, 0x82,
 0,66, 0x83, 0,66, 0x90,76, 0x91,76, 0x92,69, 0x93,38, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,44, 0x90,74,
 0x91,74, 0x92,62, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,38, 0x90,71, 0x91,71, 0x92,74, 0,66, 0x83, 0,66,
 0x80, 0x81, 0x82, 0,133, 0x93,44, 0x90,73, 0x91,73, 0x92,64, 0,66, 0x83, 0,66, 0x93,44, 0x80, 0x81, 0x82, 0,66, 0x83,
 0,66, 0x90,71, 0x91,71, 0x92,76, 0x93,38, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,44, 0x90,69, 0x91,69,
 0x92,57, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,38, 0x90,71, 0x91,71, 0x92,64, 0,66, 0x83, 0,66, 0x80,
 0x81, 0x82, 0,133, 0x93,44, 0x90,73, 0x91,73, 0x92,57, 0,66, 0x83, 0,66, 0x93,44, 0x80, 0x81, 0x82, 0,66, 0x83, 0,66,
 0x90,71, 0x91,71, 0x92,69, 0x93,38, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,44, 0x90,64, 0x91,64, 0x92,52,
 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,38, 0x90,66, 0x91,66, 0x92,59, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82,
 0,133, 0x93,44, 0x90,64, 0x91,64, 0x92,52, 0,66, 0x83, 0,66, 0x93,44, 0x80, 0x81, 0x82, 0,66, 0x83, 0,66, 0x90,64,
 0x93,38, 0,66, 0x83, 0,66, 0x80, 0,133, 0x93,44, 0x90,69, 0x91,69, 0x92,57, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82,
 0,133, 0x93,38, 0x90,76, 0x91,76, 0x92,69, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,44, 0x90,73, 0x91,73,
 0x92,57, 0,66, 0x83, 0,66, 0x93,44, 0x80, 0x81, 0x82, 0,66, 0x83, 0,66, 0x90,76, 0x91,76, 0x92,69, 0x93,38, 0,66,
 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,44, 0x90,74, 0x91,74, 0x92,62, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133,
 0x93,38, 0x90,71, 0x91,71, 0x92,74, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,44, 0x90,73, 0x91,73, 0x92,64,
 0,66, 0x83, 0,66, 0x93,44, 0x80, 0x81, 0x82, 0,66, 0x83, 0,66, 0x90,71, 0x91,71, 0x92,76, 0x93,38, 0,66, 0x83,
 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,44, 0x90,73, 0x91,73, 0x92,57, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,38,
 0x90,71, 0x91,71, 0,13, 0x92,62, 0,53, 0x83, 0,66, 0x80, 0x81, 0,13, 0x82, 0,120, 0x93,44, 0x90,69, 0x91,69,
 0x92,57, 0,66, 0x83, 0,66, 0x93,44, 0x80, 0x81, 0x82, 0,66, 0x83, 0,66, 0x90,68, 0x91,68, 0x92,64, 0x93,38, 0,66,
 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,44, 0x90,69, 0x91,69, 0x92,57, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133,
 0x93,38, 0x90,69, 0x91,69, 0x92,69, 0,66, 0x83, 0,66, 0x80, 0x81, 0x82, 0,133, 0x93,44, 0x90,69, 0x91,69, 0x92,57,
 0,66, 0x83, 0,66, 0x93,44, 0x80, 0x81, 0x82, 0,66, 0x83, 0,66, 0x93,38, 1,10, 0x83,
 0xf0
};
// This score contains 1205 bytes, and 4 tone generators are used.

