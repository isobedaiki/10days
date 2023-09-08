#include <Novice.h>

const char kWindowTitle[] = "10days";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 800, 640);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	//赤
	int playerPosx = 32;
	int playerPosy = 32;
	int xP=0, yP=0;
	int xPtmp = 0, yPtmp = 0;
	int PlayerSpeedX = 32;
	int PlayerSpeedY = 32;
	int posPXtmp = 0;
	int posPYtmp = 0;
	int isPlayerAlive = 1;


	//タイトルフレーム
	int animCounter = 0;
	int frameCounter = 0;

	//クリアフレーム
	int animCounter2 = 0;
	int frameCounter2 = 0;

	//ゴールフレーム
	int animCounter3 = 0;
	int frameCounter3 = 0;

	//青
	int player2Posx = 64;
	int player2Posy = 576;
	int xP2=0, yP2=0;
	int xPtmp2 = 0, yPtmp2 = 0;
	//int PlayerSpeed2 = 16;
	int posP2Xtmp = 0;
	int posP2Ytmp = 0;
	int isPlayerAlive2 = 1;

	//緑
	int player3Posx = 640;
	int player3Posy = 288;
	int xP3 = 0, yP3 = 0;
	int xPtmp3 = 0, yPtmp3 = 0;
	//int PlayerSpeed2 = 16;
	int posP3Xtmp = 0;
	int posP3Ytmp = 0;
	int isPlayerAlive3 = 1;

	int GOALFlag = 0;

	int blockSize = 32;
	int map[20][25]{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1},
	{1,1,1,1,1,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,0,1,1,1,0,0,1,1,1,0,0,1,0,1,0,0,1,1},
	{1,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,0,0,1,1,0,0,1,1,1},
	{1,1,0,1,1,0,0,0,1,1,0,0,0,1,0,0,0,1,0,1,1,0,0,0,1},
	{1,1,0,0,0,1,1,0,1,1,1,1,0,0,1,0,0,1,0,0,0,0,0,1,1},
	{1,1,1,1,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,1,0,1,0,1,1},
	{1,1,0,1,0,1,1,0,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0,1,1},
	{1,1,0,0,0,1,0,0,0,0,0,1,1,0,0,1,0,1,1,0,0,0,1,1,1},
	{1,0,0,1,0,0,1,1,0,1,1,1,0,0,1,0,0,0,1,0,1,0,0,0,1},
	{1,0,0,0,1,0,1,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1,1},
	{1,0,0,1,1,0,0,1,0,1,0,0,1,1,1,0,0,1,0,0,1,0,0,1,1},
	{1,0,1,0,1,1,0,0,1,0,0,1,0,0,0,0,0,0,1,1,1,1,0,1,1},
	{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1},
	{1,0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,1,1,1,0,0,0,1},
	{1,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,1,1,0,0,1},
	{1,1,0,1,1,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,1,0,1,1},
	{1,1,0,0,1,0,0,1,0,0,1,0,1,1,2,2,2,1,0,0,0,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};

	int map2[20][25]{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,0,1,0,0,0,0,0,1,0,1,0,0,1,0,0,1,0,0,0,1,0,1,1},
	{1,0,0,0,1,0,1,1,1,1,0,1,0,1,1,1,0,0,1,0,1,1,3,1,1},
	{1,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,0,1,0,0,0,1},
	{1,1,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,0,0,1,0,0,0,1,1},
	{1,0,1,0,0,1,0,0,1,1,0,0,0,1,0,0,1,0,1,1,1,0,1,1,1},
	{1,1,0,0,1,1,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,1,1},
	{1,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,1,1,0,0,1},
	{1,0,0,1,1,0,0,1,0,0,0,1,0,1,0,0,1,1,0,0,0,1,1,0,1},
	{1,0,0,0,0,0,1,0,1,0,0,2,2,2,0,0,0,0,1,0,1,0,0,0,1},
	{1,1,0,1,0,0,1,0,0,0,0,1,0,1,0,1,1,0,1,1,0,0,1,1,1},
	{1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,1,0,0,0,0,0,0,1,0,1},
	{1,1,0,0,0,0,0,1,0,0,1,1,0,1,1,0,0,1,1,0,1,0,0,0,1},
	{1,1,0,1,0,1,1,0,1,0,0,0,0,0,0,0,1,1,0,0,1,0,1,0,1},
	{1,1,1,0,0,1,1,0,0,0,1,1,0,1,0,1,0,1,1,0,0,0,0,0,1},
	{1,1,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,1,0,0,0,1,0,1,1,0,1,1,0,1,0,0,0,1,0,1,1,0,1,1},
	{1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,1,0,1,0,0,1,0,3,0,1},
	{1,3,0,1,0,0,1,0,0,0,1,0,0,0,1,1,0,1,1,0,0,0,1,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};


	int mapCountX = sizeof(map[0]) / sizeof(map[0][0]);
	int mapCountY = sizeof(map) / sizeof(map[0]);

	int map2CountX = sizeof(map2[0]) / sizeof(map2[0][0]);
	int map2CountY = sizeof(map2) / sizeof(map2[0]);

	enum MapInfo
	{
		BG,
		BLOCK,
		GOAL
	};


	//マウスカーソル非表示とフルスクリーン化(事故防止のため最後に有効化)
	//ShowCursor(FALSE);

	//シーン
	enum Scene { title, setumei, game, game2, clear };
	int scene = Scene::title;

	//クリアフラグ
	int GameClearflag = 0;

	//画面読み込み↓

	//背景画像
	int Haikei = Novice::LoadTexture("./image/BgTex.png");

	//ゴールエフェクト画像
	int GoalAnimTex[3] = {
	Novice::LoadTexture("./image/GoalEfect1.png"),
	Novice::LoadTexture("./image/GoalEfect2.png"),
	Novice::LoadTexture("./image/GoalEfect3.png"),
	};

	//プレイヤー画像
	int RedPlayer = Novice::LoadTexture("./image/RedPlayer.png");
	int BluePlayer = Novice::LoadTexture("./image/BruePlayer.png");
	int GreenPlayer = Novice::LoadTexture("./image/GreenPlayer.png");


	//タイトル画像
	int TitleAnimTex[12] = {

		Novice::LoadTexture("./image/Title1.png"),
		Novice::LoadTexture("./image/Title2.png"),
		Novice::LoadTexture("./image/Title3.png"),
		Novice::LoadTexture("./image/Title4.png"),
		Novice::LoadTexture("./image/Title5.png"),
		Novice::LoadTexture("./image/Title6.png"),
		Novice::LoadTexture("./image/Title7.png"),
		Novice::LoadTexture("./image/Title8.png"),
		Novice::LoadTexture("./image/Title9.png"),
		Novice::LoadTexture("./image/Title10.png"),
		Novice::LoadTexture("./image/Title11.png"),
		Novice::LoadTexture("./image/Title12.png")
	};

	//クリア画面
	int ClearAnimTex[12] = {

		Novice::LoadTexture("./image/GameClearTex1.png"),
		Novice::LoadTexture("./image/GameClearTex2.png"),
		Novice::LoadTexture("./image/GameClearTex3.png"),
		Novice::LoadTexture("./image/GameClearTex4.png"),
		Novice::LoadTexture("./image/GameClearTex5.png"),
		Novice::LoadTexture("./image/GameClearTex6.png"),
		Novice::LoadTexture("./image/GameClearTex7.png"),
		Novice::LoadTexture("./image/GameClearTex8.png"),
		Novice::LoadTexture("./image/GameClearTex9.png"),
		Novice::LoadTexture("./image/GameClearTex9.png"),
		Novice::LoadTexture("./image/GameClearTex9.png"),
		Novice::LoadTexture("./image/GameClearTex9.png"),
	};

	//説明画面
	int setumeiTex = Novice::LoadTexture("./image/MovesList.png");


	//壁ブロックの画像
	int WallTex = Novice::LoadTexture("./image/WallTex.png");

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///


		switch (scene) {
		case title:

			frameCounter++;
			if (frameCounter % 10 == 0) {
				animCounter++;
			}

			if (animCounter >= 12) {
				animCounter = 0;
			}

			//タイトル画像
			Novice::DrawSprite(0, 0, TitleAnimTex[animCounter], 1, 1, 0.0f, WHITE);

			//シーン切り替え
			if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0) {
				scene = setumei;
				frameCounter = 0;
			}

			break;

		case setumei:

			//説明画像
			Novice::DrawSprite(0, 0, setumeiTex, 1, 1, 0.f, WHITE);

			//シーン切り替え
			if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0) {
				scene = game;
			}

			break;

		case game:

			frameCounter3++;
			if (frameCounter3 % 10 == 0) {
				animCounter3++;
			}

			if (animCounter3 >= 3) {
				animCounter3 = 0;
			}

			//背景画像
			Novice::DrawSprite(0, 0, Haikei, 1, 1, 0.0f, WHITE);

			//ゴールエフェクト(エラー対策の仮置き)
			/*Novice::DrawSprite(0, 0, GoalEfect1, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(32, 0, GoalEfect2, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(64, 0, GoalEfect3, 1, 1, 0.0f, WHITE);*/

			if (keys[DIK_R] && preKeys[DIK_R] == 0) {

				//赤
				playerPosx = 32;
				playerPosy = 32;
				xP = 0, yP = 0;
				xPtmp = 0, yPtmp = 0;
				PlayerSpeedX = 32;
				PlayerSpeedY = 32;
				posPXtmp = 0;
				posPYtmp = 0;
				isPlayerAlive = 1;
			
				//青
				player2Posx = 64;
				player2Posy = 576;
				xP2 = 0, yP2 = 0;
				xPtmp2 = 0, yPtmp2 = 0;
				posP2Xtmp = 0;
				posP2Ytmp = 0;
				isPlayerAlive2 = 1;

				//緑
				player3Posx = 640;
				player3Posy = 288;
				xP3 = 0, yP3 = 0;
				xPtmp3 = 0, yPtmp3 = 0;
				posP3Xtmp = 0;
				posP3Ytmp = 0;
				isPlayerAlive3 = 1;

				GOALFlag = 0;
			
			}



			if (map[yP][xP] == GOAL && map[yP2][xP2] == GOAL && map[yP3][xP3]==GOAL) {

				GameClearflag = 1;

			}

			xP = playerPosx / blockSize;
			yP = playerPosy / blockSize;

			xP2 = player2Posx / blockSize;
			yP2 = player2Posy / blockSize;

			xP3 = player3Posx / blockSize;
			yP3 = player3Posy / blockSize;

			if (map[yP][xP] == GOAL && map[yP2][xP2] == GOAL && map[yP3][xP3]) {

				GOALFlag = 1;

			}


			if (keys[DIK_A] && preKeys[DIK_A] == 0) {
				posPXtmp = playerPosx - PlayerSpeedX;
				xPtmp = xP;
				yPtmp = yP;
				xPtmp = posPXtmp / blockSize;

				posP2Xtmp = player2Posx - PlayerSpeedX;
				xPtmp2 = xP2;
				yPtmp2 = yP2;
				xPtmp2 = posP2Xtmp / blockSize;

				posP3Xtmp = player3Posx - PlayerSpeedX;
				xPtmp3 = xP3;
				yPtmp3 = yP3;
				xPtmp3 = posP3Xtmp / blockSize;


				if (map[yPtmp][xPtmp] != BLOCK) {
					playerPosx -= PlayerSpeedX;
				}

				//1が2に左から当たる
				if (xPtmp2 + 1 == xPtmp && playerPosy == player2Posy) {
					playerPosx += PlayerSpeedX;
				}


				if (map[yPtmp2][xPtmp2] != BLOCK) {
					player2Posx -= PlayerSpeedX;
				}

				//2が１に左から当たる
				if (xPtmp2 == xPtmp + 1 && playerPosy == player2Posy) {
					player2Posx += PlayerSpeedX;

				}

				if (map[yPtmp3][xPtmp3] != BLOCK) {
					player3Posx -= PlayerSpeedX;
				}

				//1が3に左から当たる
				if (xPtmp3 + 1 == xPtmp && player3Posy == playerPosy) {
					playerPosx += PlayerSpeedX;
				}

				//3が1に左から当たる
				if (xPtmp3 == xPtmp + 1 && player3Posy == playerPosy) {
					player3Posx += PlayerSpeedX;
				}
				//2が3に左から当たる
				if (xPtmp3 + 1 == xPtmp2 && player3Posy == player2Posy) {
					player2Posx += PlayerSpeedX;
				}
				//3が２に左から当たる
				if (xPtmp3 == xPtmp2 + 1 && player3Posy == player2Posy) {
					player3Posx += PlayerSpeedX;
				}

			}

			if (keys[DIK_W] && preKeys[DIK_W] == 0) {
				posPYtmp = playerPosy - PlayerSpeedY;
				xPtmp = xP;
				yPtmp = yP;
				yPtmp = posPYtmp / blockSize;

				posP2Ytmp = player2Posy - PlayerSpeedY;
				xPtmp2 = xP2;
				yPtmp2 = yP2;
				yPtmp2 = posP2Ytmp / blockSize;

				posP3Ytmp = player3Posy - PlayerSpeedY;
				xPtmp3 = xP3;
				yPtmp3 = yP3;
				yPtmp3 = posP3Ytmp / blockSize;

				//上
				if (map[yPtmp][xPtmp] != BLOCK) {
					playerPosy -= PlayerSpeedY;
				}

				//1が2に上から当たる
				if (yPtmp2 + 1 == yPtmp && playerPosx == player2Posx) {
					playerPosy += PlayerSpeedY;
				}

				if (map[yPtmp2][xPtmp2] != BLOCK) {
					player2Posy -= PlayerSpeedY;
				}
				//2が1に上から当たる
				if (yPtmp2 == yPtmp + 1 && playerPosx == player2Posx) {
					player2Posy += PlayerSpeedY;
				}

				if (map[yPtmp3][xPtmp3] != BLOCK) {
					player3Posy -= PlayerSpeedY;
				}

				//1が3に上から当たる
				if (yPtmp3 + 1 == yPtmp && playerPosx == player3Posx) {
					playerPosy += PlayerSpeedY;
				}

				//3が１に上から当たる
				if (yPtmp + 1 == yPtmp3 && playerPosx == player2Posx) {
					player3Posy += PlayerSpeedY;
				}

				//2が3に上から当たる
				if (yPtmp2 == yPtmp3 + 1 && player3Posx == player2Posx) {
					player2Posy += PlayerSpeedY;
				}

				//3が2に上から当たる
				if (yPtmp2 + 1 == yPtmp3 && player3Posx == player2Posx) {
					player3Posy += PlayerSpeedY;
				}

			}

			if (keys[DIK_S] && preKeys[DIK_S] == 0) {
				posPYtmp = playerPosy + PlayerSpeedY;
				xPtmp = xP;
				yPtmp = yP;
				yPtmp = posPYtmp / blockSize;

				posP2Ytmp = player2Posy + PlayerSpeedY;
				xPtmp2 = xP2;
				yPtmp2 = yP2;
				yPtmp2 = posP2Ytmp / blockSize;

				posP3Ytmp = player3Posy + PlayerSpeedY;
				xPtmp3 = xP3;
				yPtmp3 = yP3;
				yPtmp3 = posP3Ytmp / blockSize;
				//下
				if (map[yPtmp][xPtmp] != BLOCK) {
					playerPosy += PlayerSpeedY;
				}
				//1が2に下から当たる
				if (yPtmp2 - 1 == yPtmp && playerPosx == player2Posx) {
					playerPosy -= PlayerSpeedY;
				}

				if (map[yPtmp2][xPtmp2] != BLOCK) {
					player2Posy += PlayerSpeedY;
				}
				//2が1に下から当たる
				if (yPtmp2 == yPtmp - 1 && playerPosx == player2Posx) {
					player2Posy -= PlayerSpeedY;
				}

				if (map[yPtmp3][xPtmp3] != BLOCK) {
					player3Posy += PlayerSpeedY;
				}

				//1が3に下から当たる
				if (yPtmp3 - 1 == yPtmp && playerPosx == player3Posx) {
					playerPosy -= PlayerSpeedY;
				}

				//3が1に下から当たる
				if (yPtmp - 1 == yPtmp3 && playerPosx == player3Posx) {
					player3Posy -= PlayerSpeedY;
				}

				//2が3に下から当たる
				if (yPtmp2 == yPtmp3 - 1 && player3Posx == player2Posx) {
					player2Posy -= PlayerSpeedY;
				}

				//3が2に下から当たる
				if (yPtmp3 == yPtmp2 - 1 && player3Posx == player2Posx) {
					player3Posy -= PlayerSpeedY;
				}

			}

			/// 
			if (keys[DIK_D] && preKeys[DIK_D] == 0) {
				posPXtmp = playerPosx + PlayerSpeedX;
				xPtmp = xP;
				yPtmp = yP;
				xPtmp = posPXtmp / blockSize;

				posP2Xtmp = player2Posx + PlayerSpeedX;
				xPtmp2 = xP2;
				yPtmp2 = yP2;
				xPtmp2 = posP2Xtmp / blockSize;

				posP3Xtmp = player3Posx + PlayerSpeedX;
				xPtmp3 = xP3;
				yPtmp3 = yP3;
				xPtmp3 = posP3Xtmp / blockSize;

				//右
				if (map[yPtmp][xPtmp] != BLOCK) {
					playerPosx += PlayerSpeedX;

				}
				//1が2に右に当たる
				if (xPtmp == xPtmp2 - 1 && playerPosy == player2Posy) {
					playerPosx -= PlayerSpeedX;
				}

				if (map[yPtmp2][xPtmp2] != BLOCK) {
					player2Posx += PlayerSpeedX;
				}

				//2が1に右に当たる
				if (xPtmp - 1 == xPtmp2 && playerPosy == player2Posy) {
					player2Posx -= PlayerSpeedX;
				}

				if (map[yPtmp3][xPtmp3] != BLOCK) {
					player3Posx += PlayerSpeedX;
				}

				//3が1に右から当たる
				if (xPtmp3 == xPtmp - 1 && player3Posy == playerPosy) {
					player3Posx -= PlayerSpeedX;
				}

				//１が３に右に当たる
				if (xPtmp3 - 1 == xPtmp && playerPosy == player3Posy) {
					playerPosx -= PlayerSpeedX;
				}

				//３が１に右から当たる
				if (xPtmp3 == xPtmp2 - 1 && player3Posy == player2Posy) {
					player3Posx -= PlayerSpeedX;
				}

				//２が３に右からあたる
				if (xPtmp3 - 1 == xPtmp2 && player3Posy == player2Posy) {
					player2Posx -= PlayerSpeedX;
				}

			}


			///
			/// ↓描画処理ここから
			///

			for (int y = 0; y < mapCountY; y++) {
				for (int x = 0; x < mapCountX; x++) {
					if (map[y][x] == BLOCK) {
						Novice::DrawSprite(x * blockSize, y * blockSize, WallTex, 1, 1, 0.0f, WHITE);
					}
					if (map[y][x] == GOAL) {
						Novice::DrawSprite(x * blockSize, y * blockSize, GoalAnimTex[animCounter3], 1, 1, 0.0f, WHITE);
					}

				}
			}

			if (isPlayerAlive == 1) {
				Novice::DrawSprite(playerPosx, playerPosy, RedPlayer, 1, 1, 0.0f, WHITE);
			}

			if (isPlayerAlive2 == 1) {
				Novice::DrawSprite(player2Posx, player2Posy, BluePlayer, 1, 1, 0.0f, WHITE);
			}

			if (isPlayerAlive3 == 1) {
				Novice::DrawSprite(player3Posx, player3Posy, GreenPlayer, 1, 1, 0.0f, WHITE);
			}


			///
			/// ↑描画処理ここまで
			///

				//シーン切り替え
			if (GameClearflag == 1) {

				//赤
				playerPosx = 704;
				playerPosy = 64;
				xP = 0, yP = 0;
				xPtmp = 0, yPtmp = 0;
				PlayerSpeedX = 32;
				PlayerSpeedY = 32;
				posPXtmp = 0;
				posPYtmp = 0;
				isPlayerAlive = 1;

				//青
				player2Posx = 64;
				player2Posy = 576;
				xP2 = 0, yP2 = 0;
				xPtmp2 = 0, yPtmp2 = 0;
				posP2Xtmp = 0;
				posP2Ytmp = 0;
				isPlayerAlive2 = 1;

				//緑
				player3Posx = 704;
				player3Posy = 544;
				xP3 = 0, yP3 = 0;
				xPtmp3 = 0, yPtmp3 = 0;
				posP3Xtmp = 0;
				posP3Ytmp = 0;
				isPlayerAlive3 = 1;

				

				scene = game2;

				



			}

			break;


		//------------------------------------------------------------------------------------------------------------------------------//
			case game2:

				if (keys[DIK_R] && preKeys[DIK_R] == 0) {

					//赤
					playerPosx = 704;
					playerPosy = 64;
					xP = 0, yP = 0;
					xPtmp = 0, yPtmp = 0;
					PlayerSpeedX = 32;
					PlayerSpeedY = 32;
					posPXtmp = 0;
					posPYtmp = 0;
					isPlayerAlive = 1;

					//青
					player2Posx = 64;
					player2Posy = 576;
					xP2 = 0, yP2 = 0;
					xPtmp2 = 0, yPtmp2 = 0;
					posP2Xtmp = 0;
					posP2Ytmp = 0;
					isPlayerAlive2 = 1;

					//緑
					player3Posx = 704;
					player3Posy = 544;
					xP3 = 0, yP3 = 0;
					xPtmp3 = 0, yPtmp3 = 0;
					posP3Xtmp = 0;
					posP3Ytmp = 0;
					isPlayerAlive3 = 1;


				}

				if (map2[yP][xP] == GOAL && map2[yP2][xP2] == GOAL && map2[yP3][xP3] == GOAL) {

					GameClearflag = 2;

				}

				xP = playerPosx / blockSize;
				yP = playerPosy / blockSize;

				xP2 = player2Posx / blockSize;
				yP2 = player2Posy / blockSize;

				xP3 = player3Posx / blockSize;
				yP3 = player3Posy / blockSize;


				if (keys[DIK_A] && preKeys[DIK_A] == 0) {
					posPXtmp = playerPosx - PlayerSpeedX;
					xPtmp = xP;
					yPtmp = yP;
					xPtmp = posPXtmp / blockSize;

					posP2Xtmp = player2Posx - PlayerSpeedX;
					xPtmp2 = xP2;
					yPtmp2 = yP2;
					xPtmp2 = posP2Xtmp / blockSize;

					posP3Xtmp = player3Posx - PlayerSpeedX;
					xPtmp3 = xP3;
					yPtmp3 = yP3;
					xPtmp3 = posP3Xtmp / blockSize;


					if (map2[yPtmp][xPtmp] != BLOCK) {
						playerPosx -= PlayerSpeedX;
					}

					//1が2に左から当たる
					if (xPtmp2 + 1 == xPtmp && playerPosy == player2Posy) {
						playerPosx += PlayerSpeedX;
					}


					if (map2[yPtmp2][xPtmp2] != BLOCK) {
						player2Posx -= PlayerSpeedX;
					}

					//2が１に左から当たる
					if (xPtmp2 == xPtmp + 1 && playerPosy == player2Posy) {
						player2Posx += PlayerSpeedX;

					}

					if (map2[yPtmp3][xPtmp3] != BLOCK) {
						player3Posx -= PlayerSpeedX;
					}

					//1が3に左から当たる
					if (xPtmp3 + 1 == xPtmp && player3Posy == playerPosy) {
						playerPosx += PlayerSpeedX;
					}

					//3が1に左から当たる
					if (xPtmp3 == xPtmp + 1 && player3Posy == playerPosy) {
						player3Posx += PlayerSpeedX;
					}
					//2が3に左から当たる
					if (xPtmp3 + 1 == xPtmp2 && player3Posy == player2Posy) {
						player2Posx += PlayerSpeedX;
					}
					//3が２に左から当たる
					if (xPtmp3 == xPtmp2 + 1 && player3Posy == player2Posy) {
						player3Posx += PlayerSpeedX;
					}

				}

				if (keys[DIK_W] && preKeys[DIK_W] == 0) {
					posPYtmp = playerPosy - PlayerSpeedY;
					xPtmp = xP;
					yPtmp = yP;
					yPtmp = posPYtmp / blockSize;

					posP2Ytmp = player2Posy - PlayerSpeedY;
					xPtmp2 = xP2;
					yPtmp2 = yP2;
					yPtmp2 = posP2Ytmp / blockSize;

					posP3Ytmp = player3Posy - PlayerSpeedY;
					xPtmp3 = xP3;
					yPtmp3 = yP3;
					yPtmp3 = posP3Ytmp / blockSize;

					//上
					if (map2[yPtmp][xPtmp] != BLOCK) {
						playerPosy -= PlayerSpeedY;
					}

					//1が2に上から当たる
					if (yPtmp2 + 1 == yPtmp && playerPosx == player2Posx) {
						playerPosy += PlayerSpeedY;
					}

					if (map2[yPtmp2][xPtmp2] != BLOCK) {
						player2Posy -= PlayerSpeedY;
					}
					//2が1に上から当たる
					if (yPtmp2 == yPtmp + 1 && playerPosx == player2Posx) {
						player2Posy += PlayerSpeedY;
					}

					if (map2[yPtmp3][xPtmp3] != BLOCK) {
						player3Posy -= PlayerSpeedY;
					}

					//1が3に上から当たる
					if (yPtmp3 + 1 == yPtmp && playerPosx == player3Posx) {
						playerPosy += PlayerSpeedY;
					}

					//3が１に上から当たる
					if (yPtmp + 1 == yPtmp3 && playerPosx == player2Posx) {
						player3Posy += PlayerSpeedY;
					}

					//2が3に上から当たる
					if (yPtmp2 == yPtmp3 + 1 && player3Posx == player2Posx) {
						player2Posy += PlayerSpeedY;
					}

					//3が2に上から当たる
					if (yPtmp2 + 1 == yPtmp3 && player3Posx == player2Posx) {
						player3Posy += PlayerSpeedY;
					}

				}

				if (keys[DIK_S] && preKeys[DIK_S] == 0) {
					posPYtmp = playerPosy + PlayerSpeedY;
					xPtmp = xP;
					yPtmp = yP;
					yPtmp = posPYtmp / blockSize;

					posP2Ytmp = player2Posy + PlayerSpeedY;
					xPtmp2 = xP2;
					yPtmp2 = yP2;
					yPtmp2 = posP2Ytmp / blockSize;

					posP3Ytmp = player3Posy + PlayerSpeedY;
					xPtmp3 = xP3;
					yPtmp3 = yP3;
					yPtmp3 = posP3Ytmp / blockSize;
					//下
					if (map2[yPtmp][xPtmp] != BLOCK) {
						playerPosy += PlayerSpeedY;
					}
					//1が2に下から当たる
					if (yPtmp2 - 1 == yPtmp && playerPosx == player2Posx) {
						playerPosy -= PlayerSpeedY;
					}

					if (map2[yPtmp2][xPtmp2] != BLOCK) {
						player2Posy += PlayerSpeedY;
					}
					//2が1に下から当たる
					if (yPtmp2 == yPtmp - 1 && playerPosx == player2Posx) {
						player2Posy -= PlayerSpeedY;
					}

					if (map2[yPtmp3][xPtmp3] != BLOCK) {
						player3Posy += PlayerSpeedY;
					}

					//1が3に下から当たる
					if (yPtmp3 - 1 == yPtmp && playerPosx == player3Posx) {
						playerPosy -= PlayerSpeedY;
					}

					//3が1に下から当たる
					if (yPtmp - 1 == yPtmp3 && playerPosx == player3Posx) {
						player3Posy -= PlayerSpeedY;
					}

					//2が3に下から当たる
					if (yPtmp2 == yPtmp3 - 1 && player3Posx == player2Posx) {
						player2Posy -= PlayerSpeedY;
					}

					//3が2に下から当たる
					if (yPtmp3 == yPtmp2 - 1 && player3Posx == player2Posx) {
						player3Posy -= PlayerSpeedY;
					}

				}

				/// 
				if (keys[DIK_D] && preKeys[DIK_D] == 0) {
					posPXtmp = playerPosx + PlayerSpeedX;
					xPtmp = xP;
					yPtmp = yP;
					xPtmp = posPXtmp / blockSize;

					posP2Xtmp = player2Posx + PlayerSpeedX;
					xPtmp2 = xP2;
					yPtmp2 = yP2;
					xPtmp2 = posP2Xtmp / blockSize;

					posP3Xtmp = player3Posx + PlayerSpeedX;
					xPtmp3 = xP3;
					yPtmp3 = yP3;
					xPtmp3 = posP3Xtmp / blockSize;

					//右
					if (map2[yPtmp][xPtmp] != BLOCK) {
						playerPosx += PlayerSpeedX;

					}
					//1が2に右に当たる
					if (xPtmp == xPtmp2 - 1 && playerPosy == player2Posy) {
						playerPosx -= PlayerSpeedX;
					}

					if (map2[yPtmp2][xPtmp2] != BLOCK) {
						player2Posx += PlayerSpeedX;
					}

					//2が1に右に当たる
					if (xPtmp - 1 == xPtmp2 && playerPosy == player2Posy) {
						player2Posx -= PlayerSpeedX;
					}

					if (map2[yPtmp3][xPtmp3] != BLOCK) {
						player3Posx += PlayerSpeedX;
					}

					//3が1に右から当たる
					if (xPtmp3 == xPtmp - 1 && player3Posy == playerPosy) {
						player3Posx -= PlayerSpeedX;
					}

					//１が３に右に当たる
					if (xPtmp3 - 1 == xPtmp && playerPosy == player3Posy) {
						playerPosx -= PlayerSpeedX;
					}

					//３が１に右から当たる
					if (xPtmp3 == xPtmp2 - 1 && player3Posy == player2Posy) {
						player3Posx -= PlayerSpeedX;
					}

					//２が３に右からあたる
					if (xPtmp3 - 1 == xPtmp2 && player3Posy == player2Posy) {
						player2Posx -= PlayerSpeedX;
					}

				}


				///
				/// ↓描画処理ここから
				///

				//背景画像
				Novice::DrawSprite(0, 0, Haikei, 1, 1, 0.0f, WHITE);

				for (int y = 0; y < map2CountY; y++) {
					for (int x = 0; x < map2CountX; x++) {
						if (map2[y][x] == BLOCK) {
							Novice::DrawSprite(x * blockSize, y * blockSize, WallTex, 1, 1, 0.0f, WHITE);
						}
						if (map2[y][x] == GOAL) {
							Novice::DrawSprite(x * blockSize, y * blockSize, GoalAnimTex[animCounter3], 1, 1, 0.0f, WHITE);
						}

					}
				}

				if (isPlayerAlive == 1) {
					Novice::DrawSprite(playerPosx, playerPosy, RedPlayer, 1, 1, 0.0f, WHITE);
				}

				if (isPlayerAlive2 == 1) {
					Novice::DrawSprite(player2Posx, player2Posy, BluePlayer, 1, 1, 0.0f, WHITE);
				}

				if (isPlayerAlive3 == 1) {
					Novice::DrawSprite(player3Posx, player3Posy, GreenPlayer, 1, 1, 0.0f, WHITE);
				}


				///
				/// ↑描画処理ここまで
				///





				//シーン切り替え
				if (GameClearflag == 2) {

					scene =clear;
				}

				break;



		case clear:

			
				frameCounter2++;
				if (frameCounter2 % 10 == 0) {
					animCounter2++;
				}

				if (animCounter2 >= 11) {
					animCounter2 = 11;
				}
				
			
				playerPosx = 32;
				playerPosy = 32;
				xP = 0, yP = 0;
				xPtmp = 0, yPtmp = 0;
				PlayerSpeedX = 32;
				PlayerSpeedY = 32;
				posPXtmp = 0;
				posPYtmp = 0;
				isPlayerAlive = 1;

				//青
				player2Posx = 64;
				player2Posy = 576;
				xP2 = 0, yP2 = 0;
				xPtmp2 = 0, yPtmp2 = 0;
				posP2Xtmp = 0;
				posP2Ytmp = 0;
				isPlayerAlive2 = 1;

				//緑
				player3Posx = 640;
				player3Posy = 288;
				xP3 = 0, yP3 = 0;
				xPtmp3 = 0, yPtmp3 = 0;
				posP3Xtmp = 0;
				posP3Ytmp = 0;
				isPlayerAlive3 = 1;

				GameClearflag = 0;

			//クリア画像
			Novice::DrawSprite(0, 0, ClearAnimTex[animCounter2], 1, 1, 0.0f, WHITE);

			//シーン切り替え
			if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0) {
				scene = title;
			}

			break;
		}


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
