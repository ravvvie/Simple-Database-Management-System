#include "Systems.h"

int resolution_numer = 1;
int resolution_denom = 1;

int button_id{};


error_mess take;

SDL_MessageBoxData messageboxdata {
    SDL_MESSAGEBOX_ERROR, /* .flags */
        NULL, /* .window */
        "Error!", /* .title */
        nullptr, /* .message */
        SDL_arraysize(take.buttons), /* .numbuttons */
        take.buttons, /* .buttons */
        & take.colorScheme /* .colorScheme */
};

bool Init_video(SDL_MessageBoxData& messageboxdata, SDL_Window*& window, SDL_Surface*& surface, SDL_Renderer*& render, int button_id)
{
    bool success = true;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        messageboxdata.message = SDL_GetError();
        if (SDL_ShowMessageBox(&messageboxdata, &button_id) < 0) {
            SDL_Log("error displaying message box");
            SDL_Log(SDL_GetError());
            std::cout << SDL_GetError() << std::endl;
        }
        if (button_id < 0)
        {
            SDL_Log("no selection of button \"OK\"");
        }
        success = false;
    }
    else
    {
        window = SDL_CreateWindow("IAR system", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            messageboxdata.message = SDL_GetError();
            if (SDL_ShowMessageBox(&messageboxdata, &button_id) < 0) {
                SDL_Log("error displaying message box");
                SDL_Log(SDL_GetError());
            }
            if (button_id < 0) {
                SDL_Log("no selection of button \"OK\"");
            }
            success = false;
        }
        else
        {
            surface = SDL_GetWindowSurface(window);
            if (surface == NULL)
            {
                messageboxdata.message = SDL_GetError();
                if (SDL_ShowMessageBox(&messageboxdata, &button_id) < 0)
                {
                    SDL_Log("error displaying message box");
                    SDL_Log(SDL_GetError());
                    std::cout << SDL_GetError() << std::endl;
                }
                if (button_id < 0)
                {
                    SDL_Log("no selection of button \"OK\"");
                }
                success = false;
            }
        }
    }
    render = SDL_CreateRenderer(window, -1, 0);
    if (render == NULL)
    {
        messageboxdata.message = SDL_GetError();
        if (SDL_ShowMessageBox(&messageboxdata, &button_id) < 0)
        {
            SDL_Log("error displaying message box");
            SDL_Log(SDL_GetError());
            std::cout << SDL_GetError() << std::endl;
        }
        if (button_id < 0)
        {
            SDL_Log("no selection of button \"OK\"");
        }
        success = false;
    }
    else
    {
        if (SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF) < 0)
        {
            if (SDL_ShowMessageBox(&messageboxdata, &button_id) < 0)
            {
                SDL_Log("error displaying message box");
                SDL_Log(SDL_GetError());
                std::cout << SDL_GetError() << std::endl;
            }
            if (button_id < 0)
            {
                SDL_Log("no selection of button \"OK\"");
            }
            success = false;
        }
    }

    if (TTF_Init() < 0)
    {
        if (SDL_ShowMessageBox(&messageboxdata, &button_id) < 0)
        {
            SDL_Log("error displaying message box");
            SDL_Log(SDL_GetError());
            std::cout << SDL_GetError() << std::endl;
        }
        if (button_id < 0)
        {
            SDL_Log("no selection of button \"OK\"");
        }
        success = false;
    }

    return success;
}

void exit(SDL_Window* window, SDL_Renderer* rend)
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(rend);
}
