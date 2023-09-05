#include <Novice.h>

const char kWindowTitle[] = "10days";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 800, 640);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	//マウスカーソル非表示とフルスクリーン化(事故防止のため最後に有効化)
	//ShowCursor(FALSE);
	//Novice::SetWindowMode(kFullscreen);


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

			//タイトル画像
			Novice::DrawBox(0, 0, 800, 640, 0.0f, RED, kFillModeSolid);

			//シーン切り替え
			if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0) {
				scene = setumei;
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
