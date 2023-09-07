#include <Novice.h>

const char kWindowTitle[] = "10days";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 800, 640);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	int playerPosx = 0;
	int playerPosy = 64;
	int xP, yP;
	int xPtmp = 0, yPtmp = 0;
	int PlayerSpeed = 32;
	int posPXtmp = 0;
	int posPYtmp = 0;
	int isPlayerAlive = 1;
	int animCounter = 0;
	int frameCounter = 0;

	int player2Posx = 32;
	int player2Posy = 64;
	int xP2, yP2;
	int xPtmp2 = 0, yPtmp2 = 0;
	//int PlayerSpeed2 = 16;
	int posP2Xtmp = 0;
	int posP2Ytmp = 0;
	int isPlayerAlive2 = 1;

	int blockSize = 32;
	int map[20][25]{
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,5,0,0,0,0,0,5,1,1,1,1,1,1,1,1,1 },
	{ 0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,0,0,2,0,0,0,0,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,0,3,0,0,0,0,0,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1 },
	{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,5,0,0,0,1,0,5,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	};
	int mapCountX = sizeof(map[0]) / sizeof(map[0][0]);
	int mapCountY = sizeof(map) / sizeof(map[0]);
	enum MapInfo
	{
		BG,
		BLOCK,
		REDBG,
		BLUEBG,
		diagonal,
		STRAIGHT,
	};


	//マウスカーソル非表示とフルスクリーン化(事故防止のため最後に有効化)
	//ShowCursor(FALSE);

	//シーン
	enum Scene { title, setumei, game, clear };
	int scene = Scene::title;

	//クリアフラグ
	int GameClearflag = 0;

	//画面読み込み↓
	
	//背景画像
	int Haikei = Novice::LoadTexture("./image/GameHaikei.png");

	//ゴールエフェクト画像
	int GoalEfect1 = Novice::LoadTexture("./image/GoalEfect1.png");
	int GoalEfect2 = Novice::LoadTexture("./image/GoalEfect2.png");
	int GoalEfect3 = Novice::LoadTexture("./image/GoalEfect3.png");

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


		switch (scene){
		case title:

			frameCounter++;
			if (frameCounter % 5 == 0) {
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
			Novice::DrawBox(0, 0, 800, 640, 0.0f, BLUE, kFillModeSolid);

			//シーン切り替え
			if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0) {
				scene = game;
			}

			break;

		case game:

			//背景画像
			Novice::DrawSprite(0, 0, Haikei, 1, 1, 0.0f, WHITE);

			//ゴールエフェクト(エラー対策の仮置き)
			Novice::DrawSprite(0, 0, GoalEfect1, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(32, 0, GoalEfect2, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(64, 0, GoalEfect3, 1, 1, 0.0f, WHITE);
			
			xP = playerPosx / blockSize;
			yP = playerPosy / blockSize;

			xP2 = player2Posx / blockSize;
			yP2 = player2Posy / blockSize;


			if (keys[DIK_A] && preKeys[DIK_A] == 0) {
				posPXtmp = playerPosx - PlayerSpeed;
				xPtmp = xP;
				yPtmp = yP;
				xPtmp = posPXtmp / blockSize;

				posP2Xtmp = player2Posx - PlayerSpeed;
				xPtmp2 = xP2;
				yPtmp2 = yP2;
				xPtmp2 = posP2Xtmp / blockSize;

				if (map[yPtmp][xPtmp] != BLOCK) {
					playerPosx -= PlayerSpeed;
				}
				if (xPtmp2 + 1 == xPtmp && playerPosy == player2Posy) {
					playerPosx += PlayerSpeed;
				}


				if (map[yPtmp2][xPtmp2] != BLOCK) {
					player2Posx -= PlayerSpeed;
				}

				if (xPtmp2 == xPtmp + 1 && playerPosy == player2Posy) {
					player2Posx += PlayerSpeed;

				}
			}

			if (keys[DIK_W] && preKeys[DIK_W] == 0) {
				posPYtmp = playerPosy - PlayerSpeed;
				xPtmp = xP;
				yPtmp = yP;
				yPtmp = posPYtmp / blockSize;

				posP2Ytmp = player2Posy - PlayerSpeed;
				xPtmp2 = xP2;
				yPtmp2 = yP2;
				yPtmp2 = posP2Ytmp / blockSize;


				//上
				if (map[yPtmp][xPtmp] != BLOCK) {
					playerPosy -= PlayerSpeed;
				}

				if (yPtmp2 + 1 == yPtmp && playerPosx == player2Posx) {
					playerPosy += PlayerSpeed;
				}

				if (map[yPtmp2][xPtmp2] != BLOCK) {
					player2Posy -= PlayerSpeed;
				}

				if (yPtmp2 == yPtmp + 1 && playerPosx == player2Posx) {
					player2Posy += PlayerSpeed;
				}

			}

			if (keys[DIK_S] && preKeys[DIK_S] == 0) {
				posPYtmp = playerPosy + PlayerSpeed;
				xPtmp = xP;
				yPtmp = yP;
				yPtmp = posPYtmp / blockSize;

				posP2Ytmp = player2Posy + PlayerSpeed;
				xPtmp2 = xP2;
				yPtmp2 = yP2;
				yPtmp2 = posP2Ytmp / blockSize;

				//下
				if (map[yPtmp][xPtmp] != BLOCK) {
					playerPosy += PlayerSpeed;
				}

				if (yPtmp2 - 1 == yPtmp && playerPosx == player2Posx) {
					playerPosy -= PlayerSpeed;
				}

				if (map[yPtmp2][xPtmp2] != BLOCK) {
					player2Posy += PlayerSpeed;
				}

				if (yPtmp2 == yPtmp - 1 && playerPosx == player2Posx) {
					player2Posy -= PlayerSpeed;
				}
			}

			/// 
			if (keys[DIK_D] && preKeys[DIK_D] == 0) {
				posPXtmp = playerPosx + PlayerSpeed;
				xPtmp = xP;
				yPtmp = yP;
				xPtmp = posPXtmp / blockSize;

				posP2Xtmp = player2Posx + PlayerSpeed;
				xPtmp2 = xP2;
				yPtmp2 = yP2;
				xPtmp2 = posP2Xtmp / blockSize;



				//右
				if (map[yPtmp][xPtmp] != BLOCK) {
					playerPosx += PlayerSpeed;

				}
				if (xPtmp == xPtmp2 - 1 && playerPosy == player2Posy) {
					playerPosx -= PlayerSpeed;
				}

				if (map[yPtmp2][xPtmp2] != BLOCK) {
					player2Posx += PlayerSpeed;
				}
				if (xPtmp - 1 == xPtmp2 && playerPosy == player2Posy) {
					player2Posx -= PlayerSpeed;
				}
			}

			Novice::ScreenPrintf(0, 0, "%d,%d", yPtmp, xPtmp);
			Novice::ScreenPrintf(0, 50, "%d,%d", yPtmp2, xPtmp2);


		///
		/// ↓描画処理ここから
		///

			for (int y = 0; y < mapCountY; y++) {
				for (int x = 0; x < mapCountX; x++) {
					if (map[y][x] == BLOCK) {
						Novice::DrawBox(x * blockSize, y * blockSize, 32, 32, 0.0f, WHITE,
							kFillModeWireFrame);
					}
					if (map[y][x] == BG) {
						Novice::DrawBox(x * blockSize, y * blockSize, 32, 32, 0.0f, BLACK, kFillModeSolid);
					}
					if (map[y][x] == diagonal) {
						Novice::DrawBox(x * blockSize, y * blockSize, 32, 32, 0.0f, 0xFFFF00FF, kFillModeSolid);
					}
					if (map[y][x] == REDBG) {
						Novice::DrawBox(x * blockSize, y * blockSize, 32, 32, 0.0f, RED, kFillModeSolid);
					}
					if (map[y][x] == BLUEBG) {
						Novice::DrawBox(x * blockSize, y * blockSize, 32, 32, 0.0f, BLUE, kFillModeSolid);
					}

				}
			}

			if (isPlayerAlive == 1) {
				Novice::DrawBox(playerPosx, playerPosy, 32, 32, 0.0f, RED, kFillModeSolid);
			}

			if (isPlayerAlive2 == 1) {
				Novice::DrawBox(player2Posx, player2Posy, 32, 32, 0.0f, GREEN, kFillModeWireFrame);
			}

		///
		/// ↑描画処理ここまで
		///
		
			//シーン切り替え
		    if(GameClearflag == 1){
		    	scene = clear;
		    }

			break;

		case clear:

			//クリア画像
			Novice::DrawBox(0, 0, 800, 640, 0.0f, GREEN, kFillModeSolid);

			//シーン切り替え
			if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0) {
				scene = title;
				GameClearflag = 0;
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
