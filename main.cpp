#include <iostream>
#include <raylib.h>
#include <card.hpp>

typedef enum GameScreen {TITLE, GAMEPLAY} GameScreen;

void DrawTitleScreen(){
    DrawText("ROGUE LINEAGE (FREAKY EDITION)", 225, 10, 20, RAYWHITE);
    DrawText("Press [Enter] to continue", 225, 100, 20, RAYWHITE);
    DrawText("Press [ESC] to exit", 225, 200, 20, RAYWHITE);
}

void DrawGameplayScreen(Texture2D background_texture){
    if (background_texture.id != 0) {
        DrawTexture(background_texture, 0, 0, WHITE);
    } else {
        DrawText("Background texture failed to load!", 100, 100, 20, RED);
    }
}


int main () {

    const int SCREEN_WIDTH = 1440;
    const int SCREEN_HEIGHT = 820;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "My first PEAK program!");
    SetTargetFPS(60);

    Image shinobi_image = LoadImage("imgs/profiles/castellan_shinobi.png");
    Image sentinel_cross_background = LoadImage("imgs/backgrounds/sentinelcross.png");
    ImageResize(&sentinel_cross_background, SCREEN_WIDTH, SCREEN_HEIGHT);
    Texture2D background_texture = LoadTextureFromImage(sentinel_cross_background);
    UnloadImage(sentinel_cross_background); 
    ImageResize(&shinobi_image, 150, 120);
    SetWindowIcon(shinobi_image);
    Texture2D shinobi_texture = LoadTextureFromImage(shinobi_image); 
    UnloadImage(shinobi_image); 

    race castellan = race("Castellan", "TEMP", 100, 10, 2, 0, 10, false, false, {}, {}, {});
    character shinobi = character("Shinobi", "A master of stealth and agility", &castellan, shinobi_texture);
    card shinobi_card = card(&shinobi);

    GameScreen currentScreen = TITLE;

    while (!WindowShouldClose()){
        switch(currentScreen){
            case TITLE:
            {
                if (IsKeyPressed(KEY_ENTER)){
                    currentScreen = GAMEPLAY;
                }
            } break;
            case GAMEPLAY:
            {
                if (IsKeyPressed(KEY_ESCAPE)){
                    currentScreen = TITLE;
                }
            } break;
        }

        BeginDrawing();
        ClearBackground(GREEN);
        switch(currentScreen){
            case TITLE:
            {
                DrawTitleScreen();
            } break;
            case GAMEPLAY:
            {
                DrawGameplayScreen(background_texture);
                shinobi_card.draw_card(100,  100, 170, 200);
            } break;
        }
        EndDrawing();
    }

    UnloadTexture(shinobi_texture);
    CloseWindow();

    return 0;
}
