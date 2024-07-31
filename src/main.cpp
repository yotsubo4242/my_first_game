#include "game.h"

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);          // GLUT初期化
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(640, 480);   // ウィンドウサイズの指定
	glutCreateWindow("window");     // 表示ウィンドウ作成
	glutReshapeFunc(reshape);       // Reshapeコールバック関数の指定
	glutDisplayFunc(display);       // Displayコールバック関数の指定

	glutKeyboardFunc(keyboard);     // 通常キーコールバック関数の指定(押したとき)
	glutSpecialFunc(specialKey);    // 特殊キーコールバック関数の指定(押したとき)
	glutSpecialUpFunc(specialKeyUp);// 特殊キーコールバック関数の指定(離したとき)

	glutTimerFunc(20, timer, 20);   // 定期的に呼び出される関数の指定

	// 自機の構造体データを初期化
	myShip.x = 0;	// 自機の初期位置(X座標)
	myShip.z = 0;	// 自機の初期位置(Z座標)
	myShip.isAlive = 1;	// 自機は生きている
	// 弾の構造体データを初期化(弾はZ軸方向に毎フレーム-1.0移動する)
	for(int i=0; i<MAX_SHOT; i++){
		myShip.myShot[i].isAlive = 0; // 弾は発射されていない
		myShip.myShot[i].x = 0;		// 弾の初期位置(X座標)
		myShip.myShot[i].z = 0;		// 弾の初期位置(X座標)
		myShip.myShot[i].vx = 0;	// 弾の基本速度(X座標)
		myShip.myShot[i].vz = -1.0; // 弾の基本速度(X座標)

	}
	// 敵の構造体データを初期化(敵はZ軸方向に毎フレーム0.1移動する)
	for(int i=0; i<MAX_ENEMY; i++){
		enemy[i].isAlive = 0; // 敵は出現していない
		enemy[i].x = 0;		// 敵の初期位置(X座標)
		enemy[i].z = -100;	// 敵の初期位置(Z座標)
		enemy[i].vx = 0;	// 敵の基本速度(X座標)
		enemy[i].vz = 0.1;	// 敵の基本速度(Z座標)
	}

	lightInit();    // 光源の初期設定(まとめて関数にしているだけ)
	glutMainLoop(); // メインループへ

	return 0;
}
