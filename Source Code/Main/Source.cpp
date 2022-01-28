#include "Objects.h"


int main(int argc, char* argv[])
{
    SDL_Window* window = nullptr;
    SDL_Surface* surface = nullptr;
    SDL_Renderer* render = nullptr;
    setlocale(LC_ALL, "Russian");
    if (!Init_video(messageboxdata, window, surface, render, button_id))
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
        return -1;
    }
    else
    {
        int flag = IMG_INIT_PNG;
        int init = IMG_Init(flag);
        if ((flag & init) != flag)
        {
            messageboxdata.message = IMG_GetError();
            if (SDL_ShowMessageBox(&messageboxdata, &button_id) < 0)
            {
                SDL_Log("error displaying message box");
                SDL_Log(IMG_GetError());
                std::cout << IMG_GetError() << std::endl;
            }
            if (button_id < 0)
            {
                SDL_Log("no selection of button \"OK\"");
            }
            return -2;
        }

        bool gen_quit = false;
        bool events_quit{};
        const int FPS = 60;
        const int frameDelay = 2500 / FPS;
        int counter{};
        int check_update{};
        Uint32 framestart;
        int frameTime;
        int state_process_rend_main_menu{};
        int mouse_x{};
        int mouse_y{};
        int menu_events{};


        Main_Menu current_Menu(render);

        SDL_Texture* map = TextureManager::TextureService("theme_main.png", render);

        SDL_Event glaive{};
        SDL_MouseButtonEvent glaive_mouse{};

        d_l_List IAR(render);

        _fac buff_f;
        _stud buff_s;
        buff_fac sub_f{};
        buff_stud sub_s{};
        int stud_ind{};

        std::string text = u8"";
        std::string buff_str = "";
        std::wstring sym_str = L"";
        std::wstring wbuff_str = L"";
        bool err_type = false;
        int wchars_num{};
        int chars_num{};
        SDL_Texture* buff_str_text = nullptr;
        SDL_Rect buff_str_rect{};
        buff_str_rect.y = 350;
        current_Menu.Set_Centre_Rect(&buff_str_rect, 1280);
        int state_choose{};


        int stud_quant{};
        int check_state_plus{};
        int event_state{};
        int state_rendering{};
        flag = 0;
        int flag_editing{};

        
        std::ifstream if_fac(L"fac_base.db", std::ifstream::in | std::ifstream::app | std::ifstream::binary);
        std::ifstream if_stud(L"stud_base.db", std::ifstream::in | std::ifstream::app | std::ifstream::binary);
        input_data(IAR, if_fac, if_stud, stud_quant, buff_f, buff_s, render);
        
        if_stud.close();
        if_fac.close();

        std::ofstream of_fac(L"fac_base.db", std::ofstream::out | std::ofstream::app | std::ofstream::binary);
        std::ofstream of_stud(L"stud_base.db", std::ofstream::out | std::ofstream::app | std::ofstream::binary);

        while (!gen_quit)
        {
            framestart = SDL_GetTicks();
            while (SDL_PollEvent(&glaive) != 0)
            {
                switch (glaive.type)
                {
                    case(SDL_QUIT):
                    {
                        gen_quit = true;
                        break;
                    }
                    case SDL_KEYDOWN:
                    {
                        if (glaive.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                            gen_quit = true;
                        break;
                    }
                    
                    case SDL_MOUSEBUTTONDOWN:
                    {
                        glaive_mouse = glaive.button;
                        if (glaive_mouse.button == SDL_BUTTON_LEFT)
                        {
                            if (current_Menu.key_state_buttons[0])
                            {
                                events_quit = false;
                                while (!events_quit)
                                {
                                    framestart = SDL_GetTicks();
                                    while (SDL_PollEvent(&glaive) != 0)
                                    {
                                        switch (glaive.type)
                                        {
                                        case(SDL_QUIT):
                                        {
                                            events_quit = true;
                                            gen_quit = true;
                                            break;
                                        }
                                        case SDL_KEYDOWN:
                                        {
                                            if (glaive.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                                                events_quit = true;
                                            break;
                                        }
                                        case SDL_MOUSEBUTTONDOWN:
                                        {
                                            glaive_mouse = glaive.button;
                                            SDL_GetMouseState(&mouse_x, &mouse_y);
                                            check_state_plus = IAR.mouse_state_on_plus(mouse_x, mouse_y, render);
                                            if (check_state_plus < IAR.Get_size_fac())
                                                IAR.change_state_node(render, check_state_plus);
                                            break;
                                        }
                                        case SDL_MOUSEWHEEL:
                                        {
                                            if (glaive.wheel.y > 0)
                                                IAR.scroll_list(80);
                                            else   
                                                IAR.scroll_list(-80);
                                        }
                                        }
                                    }

                                    if (SDL_RenderClear(render) < 0)
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
                                        return -4;
                                    }


                                    SDL_GetMouseState(&mouse_x, &mouse_y);
                                    IAR.mouse_state_on_plus(mouse_x, mouse_y, render);

                                    if (SDL_RenderCopy(render, map, NULL, NULL) < 0)
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
                                        return -101;
                                    }
                                   

                                    if (IAR.Get_size_fac() > 0)
                                    {
                                        state_rendering = IAR.show_list(render);
                                        if (state_rendering < 0)
                                        {
                                            events_quit = true;
                                            gen_quit = true;
                                        }
                                    }
                                    SDL_RenderPresent(render);

                                    frameTime = SDL_GetTicks() - framestart;
                                    if (frameDelay > frameTime)
                                    {
                                        SDL_Delay(frameDelay - frameTime);
                                    }

                                }
                            }
                            if (current_Menu.key_state_buttons[1])
                            {
                                events_quit = false;
                                event_state = 0;
                                menu_events = 2;
                                current_Menu.tables_for_input(event_state, render, menu_events);
                                SDL_StartTextInput();
                                while (!events_quit)
                                {
                                    framestart = SDL_GetTicks();

                                    while (SDL_PollEvent(&glaive) != 0)
                                    {
                                        switch (glaive.type)
                                        {
                                        case(SDL_QUIT):
                                        {
                                            events_quit = true;
                                            gen_quit = true;
                                            break;
                                        }
                                        case SDL_KEYDOWN:
                                        {
                                            switch (glaive.key.keysym.scancode)
                                            {
                                            case (SDL_SCANCODE_ESCAPE):
                                            {
                                                events_quit = true;
                                                buff_str = "";
                                                text = u8"";
                                                wbuff_str = L"";
                                                flag = 0;
                                                err_type = false;
                                                SDL_StopTextInput();
                                                break;
                                            }
                                            case (SDL_SCANCODE_BACKSPACE):
                                            {
                                                if (buff_str != "")
                                                {
                                                    buff_str.erase(buff_str.length() - 1, 1);
                                                    wbuff_str.erase(wbuff_str.length() - 1, 1);
                                                    if (buff_str_text != nullptr)
                                                        SDL_DestroyTexture(buff_str_text);
                                                    buff_str_text = TextureManager::TextureRender_Text(render, wbuff_str, current_Menu.Get_Font_Menu(), current_Menu.Get_Color_Menu());
                                                    SDL_QueryTexture(buff_str_text, NULL, NULL, &buff_str_rect.w, &buff_str_rect.h);
                                                    current_Menu.Set_Centre_Rect(&buff_str_rect, 1280);
                                                }
                                                break;
                                            }
                                            case(SDL_SCANCODE_RETURN):
                                            {
                                                switch (event_state)
                                                {
                                                case(1):
                                                {
                                                    if (IAR.check_direct_fac(wbuff_str))
                                                    {
                                                        err_type = false;
                                                        sub_f.direct = std::stoi(buff_str);
                                                        buff_f.direct = sub_f.direct;
                                                        event_state += 2;
                                                        current_Menu.tables_for_input(event_state, render, menu_events);
                                                    }
                                                    else
                                                    {
                                                        err_type = true;
                                                        current_Menu.Message_error(1, render, 0);
                                                    }
                                                    break;
                                                }
                                                case(3):
                                                {
                                                    if ((buff_str != "") && (buff_str.find(" ") == buff_str.npos))
                                                    {
                                                        if (buff_str.size() < 3)
                                                        {
                                                            err_type = true;
                                                            current_Menu.Message_error(5, render, 3);
                                                            break;
                                                        }
                                                        if (IAR.check_name_fac(buff_f.denom) == -1)
                                                        {
                                                            err_type = true;
                                                            current_Menu.Message_error(5, render, 6);
                                                            break;
                                                        }
                                                        err_type = false;
                                                        sub_f.denom = buff_str;
                                                        buff_f.denom = wbuff_str;
                                                        event_state += 2;
                                                        current_Menu.tables_for_input(event_state, render, menu_events);
                                                    }
                                                    else
                                                    {
                                                        err_type = true;
                                                        current_Menu.Message_error(2, render, 0);
                                                    }
                                                    break;
                                                }
                                                case(5):
                                                {
                                                    if ((buff_str != "") && (buff_str.find(" ") == buff_str.npos))
                                                    {
                                                        if (buff_str.size() < 9)
                                                        {
                                                            err_type = true;
                                                            current_Menu.Message_error(5, render, 9);
                                                            break;
                                                        }
                                                        err_type = false;
                                                        sub_f.info = buff_str;
                                                        buff_f.info = wbuff_str;
                                                        event_state += 2;
                                                        current_Menu.tables_for_input(event_state, render, menu_events);
                                                    }
                                                    else
                                                    {
                                                        err_type = true;
                                                        current_Menu.Message_error(2, render, 0);
                                                    }
                                                    break;
                                                }
                                                case(2):
                                                {
                                                    if ((buff_str != "") && (buff_str.find(" ") == buff_str.npos))
                                                    {
                                                        if (buff_str.size() < 3)
                                                        {
                                                            err_type = true;
                                                            current_Menu.Message_error(5, render, 3);
                                                            break;
                                                        }
                                                        err_type = false;
                                                        sub_s.org = buff_str;
                                                        buff_s.org = wbuff_str;
                                                        event_state += 2;
                                                        current_Menu.tables_for_input(event_state, render, menu_events);
                                                    }
                                                    else
                                                    {
                                                        err_type = true;
                                                        current_Menu.Message_error(1, render, 0);
                                                    }
                                                    break;
                                                }
                                                case(4):
                                                {
                                                    if ((buff_str != "") && (buff_str.find(" ") == buff_str.npos))
                                                    {
                                                        if (buff_str.size() < 4)
                                                        {
                                                            err_type = true;
                                                            current_Menu.Message_error(5, render, 4);
                                                            break;
                                                        }
                                                        err_type = false;
                                                        sub_s.dir_stud = buff_str;
                                                        buff_s.dir_stud = wbuff_str;
                                                        stud_ind = IAR.check_fac_belong(buff_s);
                                                        if (stud_ind == -1)
                                                        {
                                                            event_state -= 2;
                                                            current_Menu.tables_for_input(event_state, render, menu_events);
                                                            current_Menu.Message_error(3, render, 0);
                                                            err_type = true;
                                                            break;
                                                        }
                                                        event_state += 2;
                                                        current_Menu.tables_for_input(event_state, render, menu_events);
                                                    }
                                                    else
                                                    {
                                                        err_type = true;
                                                        current_Menu.Message_error(1, render, 0);
                                                    }
                                                    break;
                                                }
                                                case(6):
                                                {
                                                    if ((buff_str != "") && (buff_str.find(" ") == buff_str.npos))
                                                    {
                                                        if (buff_str.size() < 9)
                                                        {
                                                            err_type = true;
                                                            current_Menu.Message_error(5, render, 9);
                                                            break;
                                                        }
                                                        err_type = false;
                                                        sub_s.info = buff_str;
                                                        buff_s.info = wbuff_str;
                                                        stud_ind = IAR.check_fac_belong(buff_s);
                                                        event_state++;
                                                        current_Menu.tables_for_input(event_state, render, menu_events);
                                                    }
                                                    else
                                                    {
                                                        err_type = true;
                                                        current_Menu.Message_error(1, render, 0);
                                                    }
                                                    break;
                                                }
                                                case(7):
                                                {
                                                    if ((buff_str != "") && (buff_str.find(" ") == buff_str.npos))
                                                    {
                                                        if (buff_str.size() < 2)
                                                        {
                                                            err_type = true;
                                                            current_Menu.Message_error(5, render, 2);
                                                            break;
                                                        }
                                                        err_type = false;
                                                        if (state_choose == 1)
                                                        {
                                                            sub_f._fac_member = buff_str;
                                                            buff_f._fac_member = wbuff_str;
                                                        }
                                                        else
                                                        {
                                                            sub_s.NSP = buff_str;
                                                            buff_s.NSP = wbuff_str;
                                                        }
                                                        event_state++;
                                                        current_Menu.tables_for_input(event_state, render, menu_events);
                                                    }
                                                    else
                                                    {
                                                        err_type = true;
                                                        current_Menu.Message_error(2, render, 0);
                                                    }
                                                    break;
                                                }
                                                case(8):
                                                {
                                                    if ((buff_str != "") && (buff_str.find(" ") == buff_str.npos))
                                                    {
                                                        if (buff_str.size() < 3)
                                                        {
                                                            err_type = true;
                                                            current_Menu.Message_error(5, render, 3);
                                                            break;
                                                        }

                                                        err_type = false;
                                                        if (state_choose == 1)
                                                        {
                                                            sub_f._fac_member += " " + buff_str;
                                                            buff_f._fac_member += L" " + wbuff_str;
                                                        }
                                                        else
                                                        {
                                                            sub_s.NSP += " " + buff_str;
                                                            buff_s.NSP += L" " + wbuff_str;
                                                        }
                                                        event_state ++;
                                                        current_Menu.tables_for_input(event_state, render, menu_events);
                                                    }
                                                    else
                                                    {
                                                        err_type = true;
                                                        current_Menu.Message_error(2, render, 0);
                                                    }
                                                    break;
                                                }
                                                case(9):
                                                {
                                                    if (buff_str.size() < 6)
                                                    {
                                                        err_type = true;
                                                        current_Menu.Message_error(5, render, 6);
                                                        break;
                                                    }
                                                    if ((buff_str != "") && (buff_str.find(" ") == buff_str.npos))
                                                    {
                                                        err_type = false;
                                                        if (state_choose == 1)
                                                        {
                                                            sub_f._fac_member += " " + buff_str;
                                                            buff_f._fac_member += L" " + wbuff_str;
                                                            output_data_fac(of_fac, sub_f);
                                                            IAR.push_back_fac(buff_f, render);
                                                        }
                                                        else
                                                        {
                                                            sub_s.NSP += " " + buff_str;
                                                            buff_s.NSP += L" " + wbuff_str;
                                                            stud_quant++;
                                                            sub_s.ID = stud_quant;
                                                            buff_s.ID = stud_quant;
                                                            IAR.push_back_stud(buff_s, stud_ind, render);
                                                            output_data_stud(of_stud, sub_s);
                                                        }
                                                        event_state++;
                                                        current_Menu.tables_for_input(event_state, render, menu_events);
                                                        SDL_StopTextInput();
                                                    }
                                                    else
                                                    {
                                                        err_type = true;
                                                        current_Menu.Message_error(2, render, 0);
                                                    }
                                                    break;
                                                }
                                                }
                                                buff_str = "";
                                                text = u8"";
                                                wbuff_str = L"";
                                                break;
                                            }
                                            }
                                            if ((glaive.key.keysym.scancode == SDL_SCANCODE_1 || glaive.key.keysym.scancode == SDL_SCANCODE_2) && event_state == 0)
                                            {
                                                if (glaive.key.keysym.scancode == SDL_SCANCODE_1)
                                                {
                                                    state_choose = 1;
                                                    event_state++;
                                                    current_Menu.tables_for_input(event_state, render, menu_events);
                                                }
                                                if (glaive.key.keysym.scancode == SDL_SCANCODE_2)
                                                {
                                                    state_choose = 2;
                                                    event_state += 2;
                                                    current_Menu.tables_for_input(event_state, render, menu_events);
                                                }
                                            }
                                            break;
                                        }
                                        case SDL_TEXTINPUT:
                                        {
                                            if ((event_state) > 0)
                                            {
                                                if (flag != 0)
                                                {
                                                    flag_editing = 0;
                                                    switch (event_state)
                                                    {
                                                    case (1):
                                                    {
                                                        if (buff_str.size() >= 1)
                                                            flag_editing = 1;
                                                        break;
                                                    }
                                                    case (2):
                                                    {
                                                        if (buff_str.size() >= 13)
                                                            flag_editing = 1;
                                                        break;
                                                    }
                                                    case (3):
                                                    {
                                                        if (buff_str.size() >= 13)
                                                            flag_editing = 1;
                                                        break;
                                                    }
                                                    case (4):
                                                    {
                                                        if (buff_str.size() >= 7)
                                                            flag_editing = 1;
                                                        break;
                                                    }
                                                    case (5):
                                                    {
                                                        if (buff_str.size() >= 18)
                                                            flag_editing = 1;
                                                        break;
                                                    }
                                                    case (6):
                                                    {
                                                        if (buff_str.size() >= 18)
                                                            flag_editing = 1;
                                                        break;
                                                    }
                                                    case (7):
                                                    {
                                                        if (buff_str.size() >= 15)
                                                            flag_editing = 1;
                                                        break;
                                                    }
                                                    case (8):
                                                    {
                                                        if (buff_str.size() >= 15)
                                                            flag_editing = 1;
                                                        break;
                                                    }
                                                    case (9):
                                                    {
                                                        if (buff_str.size() >= 15)
                                                            flag_editing = 1;
                                                        break;
                                                    }
                                                    }

                                                    if (flag_editing != 0)
                                                        break;

                                                    text += glaive.text.text;
                                                    if (buff_str_text != nullptr)
                                                        SDL_DestroyTexture(buff_str_text);
                                                    wchars_num = MultiByteToWideChar(CP_UTF8, 0, text.c_str(), -1, NULL, 0);
                                                    sym_str = L"";
                                                    sym_str.resize(wchars_num);
                                                    MultiByteToWideChar(CP_UTF8, 0, text.c_str(), -1, &sym_str[0], wchars_num);
                                                    wbuff_str += sym_str;                                                   
                                                    wbuff_str.erase(wbuff_str.length() - 1, 1);


                                                    chars_num = WideCharToMultiByte(1251, 0, &wbuff_str[0], -1, 0, 0, 0, 0);
                                                    buff_str = "";
                                                    buff_str.resize(chars_num);
                                                    WideCharToMultiByte(1251, 0, wbuff_str.c_str(), -1, &buff_str[0], chars_num - 1, 0, 0);
                                                    buff_str.erase(buff_str.length() - 1, 1);

                                                    buff_str_text = TextureManager::TextureRender_Text(render, wbuff_str, current_Menu.Get_Font_Menu(), current_Menu.Get_Color_Menu());
                                                    SDL_QueryTexture(buff_str_text, NULL, NULL, &buff_str_rect.w, &buff_str_rect.h);
                                                    current_Menu.Set_Centre_Rect(&buff_str_rect, 1280);
                                                    text = u8"";
                                                }
                                                else
                                                    flag = 1;
            
                                            }
                                            break;
                                        }                                       
                                        }
                                      
                                    }

                                    if (SDL_RenderClear(render) < 0)
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
                                        return -4;
                                    }


                                    if (SDL_RenderCopy(render, map, NULL, NULL) < 0)
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
                                        return -101;
                                    }
                                    
                                    if (err_type)
                                    if (SDL_RenderCopy(render, current_Menu.Get_buffer3(), NULL, current_Menu.Get_buff_rect(2)) < 0)
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
                                        return -101;
                                    }
                        

                                    if (event_state != 0 && buff_str != "")
                                        if (SDL_RenderCopy(render, buff_str_text, NULL, &buff_str_rect) < 0)
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
                                            return -103;

                                        }
                                   
                                    state_rendering = current_Menu.Render_events(menu_events, event_state, render);
                                    if (state_rendering < 0)
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
                                        return state_rendering;
                                    }

                                    SDL_RenderPresent(render);

                                    frameTime = SDL_GetTicks() - framestart;
                                    if (frameDelay > frameTime)
                                    {
                                        SDL_Delay(frameDelay - frameTime);
                                    }
                                }
                            }
                            if (current_Menu.key_state_buttons[2])
                            {
                                events_quit = false;
                                menu_events = 3;
                                event_state = 0;
                                state_choose = 0;
                                err_type = false;
                                current_Menu.tables_for_input(event_state, render, menu_events);
                                while (!events_quit)
                                {
                                    framestart = SDL_GetTicks();
                                    while (SDL_PollEvent(&glaive) != 0)
                                    {
                                        switch (glaive.type)
                                        {
                                        case(SDL_QUIT):
                                        {
                                            events_quit = true;
                                            gen_quit = true;
                                            break;
                                        }
                                        case SDL_KEYDOWN:
                                        {
                                            if (glaive.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                                                events_quit = true;

                                            if (state_choose == 0)
                                            {
                                                switch (glaive.key.keysym.scancode)
                                                {
                                                case(SDL_SCANCODE_1):
                                                {
                                                    err_type = false;
                                                    state_choose = 1;
                                                    if (!IAR.pars_choose_denom(state_choose))
                                                    {
                                                        state_choose = 0;
                                                        current_Menu.Message_error(4, render, 0);
                                                        err_type = true;
                                                    }
                                                    else
                                                    {
                                                        event_state++;
                                                        current_Menu.tables_for_input(event_state, render, menu_events);
                                                    }
                                                    break;
                                                }
                                                case(SDL_SCANCODE_2):
                                                {
                                                    err_type = false;
                                                    state_choose = 2;
                                                    if (!IAR.pars_choose_denom(state_choose))
                                                    {
                                                        state_choose = 0;
                                                        current_Menu.Message_error(4, render, 0);
                                                        err_type = true;
                                                    }
                                                    else
                                                    {
                                                        event_state++;
                                                        current_Menu.tables_for_input(event_state, render, menu_events);
                                                    }
                                                    break;
                                                }
                                                case(SDL_SCANCODE_3):
                                                {
                                                    err_type = false;
                                                    state_choose = 3;
                                                    if (!IAR.pars_choose_denom(state_choose))
                                                    {
                                                        state_choose = 0;
                                                        current_Menu.Message_error(4, render, 0);
                                                        err_type = true;
                                                    }
                                                    else
                                                    {
                                                        event_state++;
                                                        current_Menu.tables_for_input(event_state, render, menu_events);
                                                    }
                                                    break;
                                                }
                                                }
                                            }
                                            break;
                                        }
                                        }

                                    }

                                    if (SDL_RenderClear(render) < 0)
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
                                        return -4;
                                    }

                                    if (SDL_RenderCopy(render, map, NULL, NULL) < 0)
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
                                        return -101;
                                    }

                                    if(err_type)
                                        if (SDL_RenderCopy(render, current_Menu.Get_buffer5(), NULL, current_Menu.Get_buff_rect(4)) < 0)
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
                                            return -101;
                                        }

                                    if (state_choose != 0)
                                    {
                                        flag = IAR.render_choose_denom(state_choose, render);
                                        if (flag < 0)
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
                                            return flag;
                                        }
                                    }

                                    state_rendering = current_Menu.Render_events(menu_events, event_state, render);
                                    if (state_rendering < 0)
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
                                        return state_rendering;
                                    }

                                    SDL_RenderPresent(render);

                                    frameTime = SDL_GetTicks() - framestart;
                                    if (frameDelay > frameTime)
                                    {
                                        SDL_Delay(frameDelay - frameTime);
                                    }
                                }
                            }
                            if (current_Menu.key_state_buttons[3])
                            {
                                events_quit = false;
                                current_Menu.Stud_quant_show(stud_quant, render);
                                while (!events_quit)
                                {
                                    framestart = SDL_GetTicks();
                                    while (SDL_PollEvent(&glaive) != 0)
                                    {
                                        switch (glaive.type)
                                        {
                                        case(SDL_QUIT):
                                        {
                                            events_quit = true;
                                            gen_quit = true;
                                            break;
                                        }
                                        case SDL_KEYDOWN:
                                        {
                                            if (glaive.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                                                events_quit = true;
                                            break;
                                        }
                                        }
                                    }

                                    if (SDL_RenderCopy(render, map, NULL, NULL) < 0)
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
                                        return -101;
                                    }

                                    if (SDL_RenderCopy(render, current_Menu.Get_buffer1(), NULL, current_Menu.Get_buff_rect(0)) < 0)
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
                                        return -500;
                                    }


                                    SDL_RenderPresent(render);

                                    frameTime = SDL_GetTicks() - framestart;
                                    if (frameDelay > frameTime)
                                    {
                                        SDL_Delay(frameDelay - frameTime);
                                    }
                                }
                            }
                            if (current_Menu.key_state_buttons[4])
                            {
                                events_quit = false;
                                menu_events = 5;
                                event_state = 0;
                                current_Menu.tables_for_input(event_state, render, menu_events); 
                                while (!events_quit)
                                {
                                    framestart = SDL_GetTicks();
                                    while (SDL_PollEvent(&glaive) != 0)
                                    {
                                        switch (glaive.type)
                                        {
                                        case(SDL_QUIT):
                                        {
                                            events_quit = true;
                                            gen_quit = true;
                                            break;
                                        }
                                        case SDL_KEYDOWN:
                                        {
                                            if (glaive.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                                                events_quit = true;
                                            break;
                                        }
                                        }
                                    }

                                    if (SDL_RenderCopy(render, map, NULL, NULL) < 0)
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
                                        return -101;
                                    }

                                    state_rendering = current_Menu.Render_events(menu_events, event_state, render);
                                    if (state_rendering < 0)
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
                                        return state_rendering;
                                    }


                                    SDL_RenderPresent(render);

                                    frameTime = SDL_GetTicks() - framestart;
                                    if (frameDelay > frameTime)
                                    {
                                        SDL_Delay(frameDelay - frameTime);
                                    }
                                }
                            }
                        }
                        break;
                    }
                    
                }

            }
            
            if (gen_quit == 1)
                continue;

            SDL_GetMouseState(&mouse_x, &mouse_y);
            for (int i = 1; i <= 5; i++)
            {
                current_Menu.key_state_buttons[i - 1] = current_Menu.mouse_detection(i, mouse_x, mouse_y);
                if (current_Menu.key_state_buttons[i - 1])
                    current_Menu.change_text_color(render, 2, i);
                else
                    current_Menu.change_text_color(render, 1, i);
            }
            
            if (SDL_RenderClear(render) < 0)
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
                return -4;
            }

            if (SDL_RenderCopy(render, map, NULL, NULL) < 0)
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
                return -101;
            }

            state_process_rend_main_menu = current_Menu.Main_Menu_Render(render);
            if (state_process_rend_main_menu != 0)
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
                return state_process_rend_main_menu;
            }

            SDL_RenderPresent(render);

            frameTime = SDL_GetTicks() - framestart;
            if (frameDelay > frameTime)
            {
                SDL_Delay(frameDelay - frameTime);
            }

        }
        exit(window, render);
        of_stud.close();
        of_fac.close();
    }

    return 0;
}

