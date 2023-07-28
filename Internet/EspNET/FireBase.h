#define DATABASE_URL "https://flutter-temperatura-arduino-default-rtdb.firebaseio.com/"
#define API_KEY "AIzaSyBl5TymsKLfMySzBm1DB5ue_oA2KcsdMco"

void FireBase_Init(const char *wifi_ssid, const char *wifi_password);
void FireBase_SetInt(const char *path, int value);
