#include "Objects.h"

int d_l_List::show_list(SDL_Renderer*& rend)
{
	int state{};

	
	if (SDL_RenderCopy(rend, Table_direct_text, NULL, &Table_direct_rect) < 0)
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
		return -140;
	}

	if (SDL_RenderCopy(rend, Table_denom_text, NULL, &Table_denom_rect) < 0)
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
		return -142;
	}


	if (SDL_RenderCopy(rend, Table_fac_member_text, NULL, &Table_fac_member_rect) < 0)
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
		return -143;
	}


	if (SDL_RenderCopy(rend, Table_info_text, NULL, &Table_info_rect) < 0)
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
		return -144;
	}


	curr_fac = head_fac;

	for (int i = 0; i < size_fac; i++)
	{
		if (curr_fac->data.direct_rect.y > 80)
		{

			if (SDL_RenderCopy(rend, curr_fac->data.denom_text, NULL, &curr_fac->data.denom_rect) < 0)
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
				return -151;
			}

			if (SDL_RenderCopy(rend, curr_fac->data.direct_text, NULL, &curr_fac->data.direct_rect) < 0)
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
				return -152;
			}

			if (SDL_RenderCopy(rend, curr_fac->data.info_text, NULL, &curr_fac->data.info_rect) < 0)
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
				return -153;
			}

			if (SDL_RenderCopy(rend, curr_fac->data._fac_member_text, NULL, &curr_fac->data._fac_member_rect) < 0)
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
				return -154;
			}

			if (SDL_RenderCopy(rend, curr_fac->state_text, NULL, &curr_fac->state_rect) < 0)
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
				return -155;
			}
		}
		if (curr_fac->state == L"-")
		{
			if (curr_fac->Table_ID_rect.y > 80 )
			{
				state = curr_fac->Draw_frame_stud(rend, curr_fac);
				if (state < 0)
					return state;

				if (SDL_RenderCopy(rend, curr_fac->Table_ID_text, NULL, &curr_fac->Table_ID_rect) < 0)
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
					return -131;
				}

				if (SDL_RenderCopy(rend, curr_fac->Table_dir_stud_text, NULL, &curr_fac->Table_dir_stud_rect) < 0)
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
					return -132;
				}

				if (SDL_RenderCopy(rend, curr_fac->Table_info_text, NULL, &curr_fac->Table_info_rect) < 0)
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
					return -133;
				}

				if (SDL_RenderCopy(rend, curr_fac->Table_NSP_text, NULL, &curr_fac->Table_NSP_rect) < 0)
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
					return -134;
				}
			}

			curr_fac->curr_stud = curr_fac->head_stud;
			for (int j = 0; j < curr_fac->size_stud; j++)
			{
				if (curr_fac->curr_stud->data.dir_stud_rect.y > 80)
				{
					if (SDL_RenderCopy(rend, curr_fac->curr_stud->data.dir_stud_text, NULL, &curr_fac->curr_stud->data.dir_stud_rect) < 0)
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
						return -161;
					}

					if (SDL_RenderCopy(rend, curr_fac->curr_stud->data.ID_text, NULL, &curr_fac->curr_stud->data.ID_rect) < 0)
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
						return -162;
					}


					if (SDL_RenderCopy(rend, curr_fac->curr_stud->data.info_text, NULL, &curr_fac->curr_stud->data.info_rect) < 0)
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
						return -163;
					}

					if (SDL_RenderCopy(rend, curr_fac->curr_stud->data.NSP_text, NULL, &curr_fac->curr_stud->data.NSP_rect) < 0)
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
						return -164;
					}
				}
				curr_fac->curr_stud = curr_fac->curr_stud->pNext_stud;
			}
		}

		curr_fac = curr_fac->pNext_fac;
	}

	state = Draw_frames_fac(rend);
	if (state < 0)
		return state;

	return 0;
}

int d_l_List::Draw_frames_fac(SDL_Renderer*& rend)
{


	if (SDL_RenderDrawLine(rend, 90, 30, 1100, 30) < 0)
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
		return -200;
	}

	if (SDL_RenderDrawLine(rend, 90, 80, 1100, 80) < 0)
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
		return -201;
	}

	return 0;
}


int d_l_List::Node_fac::Draw_frame_stud(SDL_Renderer*& rend, Node_fac* curr)
{
	if (SDL_RenderDrawLine(rend, curr->Table_ID_rect.x - 5, curr->Table_ID_rect.y - 3, curr->Table_info_rect.x + curr->Table_info_rect.w + 5, curr->Table_ID_rect.y - 3) < 0)
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
		return -210;
	}

	if (SDL_RenderDrawLine(rend, curr->Table_ID_rect.x - 5, curr->Table_ID_rect.y + curr->Table_ID_rect.h + 3, curr->Table_info_rect.x + curr->Table_info_rect.w + 5, curr->Table_ID_rect.y + curr->Table_ID_rect.h + 3) < 0)
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
		return -211;
	}

	return 0;
}

int d_l_List:: render_choose_denom(const int& ID_dir, SDL_Renderer*& rend)
{
	curr_fac = head_fac;
	for (int i = 0; i < size_fac; i++)
	{
		if (curr_fac->data.direct == ID_dir)
		{
			if (SDL_RenderCopy(rend, curr_fac->data.denom_text, NULL, &curr_fac->name_org_rect) < 0)
				return -400;
		}
		curr_fac = curr_fac->pNext_fac;
	}

	return 0;
}