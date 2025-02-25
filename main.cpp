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

    //Profile images TEMP LOCATION
    Image shinobi_image_p = LoadImage("imgs/profiles/castellan_shinobi.png");
    Image castellan_dragonk_p = LoadImage("imgs/profiles/castellan_dragonknight.png");
    Image sigil_commander_p = LoadImage("imgs/profiles/haseldan_sigilknightcommander.png");
    Image morvid_abyss_p = LoadImage("imgs/profiles/morvid_abyss.png");
    Image dzin_oni_p = LoadImage("imgs/profiles/dzin_oni.png");
    Image vind_illu_p = LoadImage("imgs/profiles/vind_illu.png");
    Image dzin_greatsword_p = LoadImage("imgs/profiles/dzin_greatsword.png");
    Image vind_dsk_p = LoadImage("imgs/profiles/vind_dsk.png");

    //Background images TEMP LOCATION
    Image sentinel_cross_background = LoadImage("imgs/backgrounds/sentinelcross.png");

    //Resize images
    ImageResize(&sentinel_cross_background, SCREEN_WIDTH, SCREEN_HEIGHT);
    ImageResize(&shinobi_image_p, 150, 120);
    ImageResize(&castellan_dragonk_p, 150, 120);
    ImageResize(&sigil_commander_p, 150, 120);
    ImageResize(&morvid_abyss_p, 150, 120);
    ImageResize(&dzin_oni_p, 150, 120);
    ImageResize(&vind_illu_p, 150, 120);
    ImageResize(&dzin_greatsword_p, 150, 120);
    ImageResize(&vind_dsk_p, 150, 120);
    
    //2D Render Textures
    Texture2D background_texture = LoadTextureFromImage(sentinel_cross_background);
    Texture2D castellan_dragonk_texture = LoadTextureFromImage(castellan_dragonk_p);
    Texture2D sigil_commander_texture = LoadTextureFromImage(sigil_commander_p);
    Texture2D morvid_abyss_texture = LoadTextureFromImage(morvid_abyss_p);
    Texture2D dzin_oni_texture = LoadTextureFromImage(dzin_oni_p);
    Texture2D vind_illu_texture = LoadTextureFromImage(vind_illu_p);
    Texture2D dzin_greatsword_texture = LoadTextureFromImage(dzin_greatsword_p);
    Texture2D vind_dsk_texture = LoadTextureFromImage(vind_dsk_p);
    Texture2D shinobi_texture = LoadTextureFromImage(shinobi_image_p);

    SetWindowIcon(shinobi_image_p);

    //Unload images
    UnloadImage(castellan_dragonk_p);
    UnloadImage(sigil_commander_p);
    UnloadImage(morvid_abyss_p);
    UnloadImage(dzin_oni_p);
    UnloadImage(vind_illu_p);
    UnloadImage(dzin_greatsword_p);
    UnloadImage(vind_dsk_p);
    UnloadImage(sentinel_cross_background); 
    UnloadImage(shinobi_image_p); 

    //Race initialization TEMP
    race castellan = race("Castellan", "TEMP", 100, 10, 2, 0, 10, false, false, {}, {}, {});
    race haseldan = race("Haseldan", "TEMP", 100, 10, 2, 0, 10, false, false, {}, {}, {});
    race morvid = race("Morvid", "TEMP", 100, 10, 2, 0, 10, false, false, {}, {}, {});
    race dzin = race("Dzin", "TEMP", 100, 10, 2, 0, 10, false, false, {}, {}, {});
    race vind = race("Vind", "TEMP", 100, 10, 2, 0, 10, false, false, {}, {}, {});

    //Character initialization TEMP
    character shinobi = character("Shinobi", "A master of stealth and agility", &castellan, shinobi_texture);
    character castellan_dragonknight = character("Castellan Dragonknight", "A master of the sword and shield", &castellan, castellan_dragonk_texture);
    character sigil_commander = character("Sigil Knight Commander", "A master of the sword and shield", &haseldan, sigil_commander_texture);
    character morvid_abysswalker = character("Morvid Abysswalker", "A master of the sword and shield", &morvid, morvid_abyss_texture);
    character dzin_oni = character("Dzin Oni", "A master of the sword and shield", &dzin, dzin_oni_texture);
    character vind_illu = character("Vind Illusionist", "A master of the sword and shield", &vind, vind_illu_texture);
    character dzin_greatsword = character("Dzin Greatsword", "A master of the sword and shield", &dzin, dzin_greatsword_texture);
    character vind_dsk = character("Vind Dark Sigil Knight", "A master of the sword and shield", &vind, vind_dsk_texture);

    //Card initialization TEMP
    card shinobi_card = card(&shinobi);
    card castellan_dragonknight_card = card(&castellan_dragonknight);
    card sigil_commander_card = card(&sigil_commander);
    card morvid_abysswalker_card = card(&morvid_abysswalker);
    card dzin_oni_card = card(&dzin_oni);
    card vind_illu_card = card(&vind_illu);
    card dzin_greatsword_card = card(&dzin_greatsword);
    card vind_dsk_card = card(&vind_dsk);

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

                DrawText("Turn Order", (SCREEN_WIDTH - MeasureText("Turn Order", 50)) / 2, 10, 50, RAYWHITE);

                //BOTTOM LEFT TEMP!!!
                vind_illu_card.draw_card(50, 520, 170, 200);
                castellan_dragonknight_card.draw_card(100, 540, 170, 200);
                sigil_commander_card.draw_card(150, 560, 170, 200);
                dzin_greatsword_card.draw_card(200, 580, 170, 200);

                //TOP RIGHT TEMP!!!
                morvid_abysswalker_card.draw_card(1100, 40, 170, 200);
                dzin_oni_card.draw_card(1150, 60, 170, 200);
                shinobi_card.draw_card(1200, 80, 170, 200);
                vind_dsk_card.draw_card(1250, 100, 170, 200);

                //TURN ORDER TEMP!!!
                shinobi_card.draw_card(800, 72, 170, 200);
                dzin_oni_card.draw_card(750, 74, 170, 200);
                castellan_dragonknight_card.draw_card(700, 76, 170, 200);                
                vind_illu_card.draw_card(650, 78, 170, 200);
                dzin_greatsword_card.draw_card(600, 80, 170, 200);
                sigil_commander_card.draw_card(550, 82, 170, 200);
                morvid_abysswalker_card.draw_card(500, 84, 170, 200);
                vind_dsk_card.draw_card(450, 86, 170, 200);
                
            } break;
        }
        EndDrawing();
    }

    UnloadTexture(shinobi_texture);
    CloseWindow();

    return 0;
}
