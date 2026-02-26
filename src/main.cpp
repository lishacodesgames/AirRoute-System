#define RAYGUI_IMPLEMENTATION
#include <Precompiled.h> // has raygui
#include <raylib.h>

int main() {
   InitWindow(736, 458, "Testing"); // that's the background image's dimensions
   SetTargetFPS(60);

   Texture2D background = LoadTexture("assets/bg.jpg");

   while(!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(WHITE);

      DrawTexture(background, 0, 0, WHITE);
      DrawText("Hello World!", 180, 250, 40, BLACK);
      GuiButton({0, 0, 100, 100}, "THIS IS A BUTTON");

      EndDrawing();
   }

   UnloadTexture(background);
   CloseWindow();
   return 0;
}

#if 0

#include "ui/Menu.h"
#include "ui/FlightView.h"
#include "ui/PassengerView.h"
#include "services/BookingService.h"
#include "storage/FlightStorage.h"
#include "storage/PassengerStorage.h"
#include "core/Flight.h"
#include <cstdlib>
#include <ctime>
enum class Choice {Exit, Book, ViewFlight, ViewBoardingPass, ViewAllFlights};
int main() {
   std::srand(time(0));
   //declarations TODO
   Choice choice;

   while(true) {
      choice = static_cast<Choice>(MainMenu());

      switch(choice) {
         case Choice::Exit: 
            return 0;

         case Choice::Book: {
            BookingService booker;
            booker.bookFlight();
            std::cin.get();
            break;
         }

         case Choice::ViewFlight: {
            FlightStorage storage;
            Flight f;
            bool success, shouldContinue = true;
            std::string id;

            while(shouldContinue) {
               id = getIDforShow();
               success = storage.getFlightInfo(id, f);
               if(success) {
                  printTitle();
                  printFlightInfo(f);
                  std::cin.get();
                  shouldContinue = false;
               }
               else
                  shouldContinue = promptTryAgain();
            }

            break;
         }

         case Choice::ViewBoardingPass: {
            bool success, shouldContinue = true;
            while (shouldContinue) {
               success = displayBoardingPass();
               
               if(success) {
                  std::cin.get();
                  shouldContinue = false;
               }
               else
                  shouldContinue = promptTryAgain();
            }

            break;
         }

         case Choice::ViewAllFlights: {
            displayAllFlights();
            std::cin.get();
            break;
         }
      }
   }

   return 0;
}

#endif