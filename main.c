//TODO;
//SCIENTIFIC NOTATION FUNCTION
//VECTOR NORMALIZATION



#include "raylib.h"
#include "raymath.h"
#include <math.h>


typedef struct sciNot {
    float value;
    int not;
} sciNot;

typedef struct vector2SciNot{
    sciNot x;
    sciNot y;
} vector2SciNot;

typedef struct Object {
    vector2SciNot position; 
    Vector2 velocity; 
    Vector2 acceleration;
    sciNot abdAcceleration;
    sciNot mass; 
} Object;


int main(void){
    const int screenWidth = 800;
    const int screenHeight = 450;
    sciNot G;
    double force;
    double absDistance;
    vector2SciNot distance;
    sciNot time;

    time.value = 3.65783;
    time.not = 11;

    InitWindow(screenWidth, screenHeight, "nbody");

    Camera2D camera = { 0 };
    camera.target = (Vector2){ 0, 0 };
    camera.offset = (Vector2){ screenWidth/2, screenHeight/2 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    G.value = 6.674;
    G.not   = -11;

    Object earth = {0};
    Object sun = {0};

    sun.position.x.value = 0;
    sun.position.y.value = 0;
    sun.mass.value = 1.989;
    sun.mass.not   = 30;

    earth.position.x.value = 1.5022;
    earth.position.x.not = 11;
    earth.position.y.value = 0;

    earth.mass.value = 5.972;
    earth.mass.not   = 24;

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode2D(camera);

        distance.x.value = abs(earth.position.x.value);
        distance.y.value = abs(earth.position.y.value);
        absDistance = sqrt(pow(distance.x.value, 2) + pow(distance.y.value, 2));

        force = (G.value * sun.mass.value * earth.mass.value) / (pow(absDistance, 2));

        earth.abdAcceleration.value = force / earth.mass.value;



        //velocity force * time.value;

        //(force * time^2) / m

        //365 783 040 000

        DrawCircle(earth.position.x.value * 100, earth.position.y.value * 100, 10, BLUE);

        EndMode2D();

        EndDrawing();
    }
}

