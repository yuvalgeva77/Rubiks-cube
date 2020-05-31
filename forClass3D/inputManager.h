#include "Data.h"
#pragma once   //maybe should be static class
#include "GLFW\glfw3.h"

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Data *data;
		data = (Data *)glfwGetWindowUserPointer(window);
		switch (key)
		{
		case GLFW_KEY_ESCAPE:
			if(action == GLFW_PRESS)
				glfwSetWindowShouldClose(window,GLFW_TRUE);
			break;
		case GLFW_KEY_R:
			if (action == GLFW_PRESS) {
				Sleep(10);
				data->_rcube->rotateRWall();
				data->_display->Clear(1.0f, 1.0f, 1.0f, 1.0f);
				data->_rcube->render();
				data->_display->SwapBuffers();
			}
			break;
		case GLFW_KEY_L:
			if (action == GLFW_PRESS) {
				data->_rcube->rotateLWall();
				data->_display->Clear(1.0f, 1.0f, 1.0f, 1.0f);
				data->_rcube->render();
				data->_display->SwapBuffers();
				Sleep(10);
			}
			break;
		case GLFW_KEY_U:
			if (action == GLFW_PRESS) {
				data->_rcube->rotateUWall();
				data->_display->Clear(1.0f, 1.0f, 1.0f, 1.0f);
				data->_rcube->render();
				data->_display->SwapBuffers();
				Sleep(10);
			}
			break;
		case GLFW_KEY_D:
			if (action == GLFW_PRESS) {
				data->_rcube->rotateDWall();
				data->_display->Clear(1.0f, 1.0f, 1.0f, 1.0f);
				data->_rcube->render();
				data->_display->SwapBuffers();
				Sleep(10);
			}
			break;
		case GLFW_KEY_B:
			if (action == GLFW_PRESS) {
				data->_rcube->rotateBWall();
				data->_display->Clear(1.0f, 1.0f, 1.0f, 1.0f);
				data->_rcube->render();
				data->_display->SwapBuffers();
				Sleep(10);
			}
			break;
		case GLFW_KEY_F:
			if (action == GLFW_PRESS) {
				data->_rcube->rotateFWall();
				data->_display->Clear(1.0f, 1.0f, 1.0f, 1.0f);
				data->_rcube->render();
				data->_display->SwapBuffers();
				Sleep(10);
			}
			break;
		case GLFW_KEY_Z:
			if (action == GLFW_PRESS) {
				data->_rcube->halfAngle();
			}
			break;
		case GLFW_KEY_A:
			if (action == GLFW_PRESS) {
				data->_rcube->doubleAngle();
			}
			break;
		case GLFW_KEY_SPACE:
			if (action == GLFW_PRESS) {
				data->_rcube->reverseRotaion();
			}
			break;
		default:
			break;
		}

		/*int state = glfwGetKey(window, GLFW_KEY_L);
		if (state == GLFW_PRESS) {
			Sleep(10);
			data->_rcube->rotateRWall();
			data->_display->Clear(1.0f, 1.0f, 1.0f, 1.0f);
			data->_rcube->render();
			data->_display->SwapBuffers();
		}
		state = glfwGetKey(window, GLFW_KEY_L);
		if (state == GLFW_PRESS) {
			Sleep(10);
			data->_rcube->rotateLWall();
			data->_display->Clear(1.0f, 1.0f, 1.0f, 1.0f);
			data->_rcube->render();
			data->_display->SwapBuffers();
		}
		state = glfwGetKey(window, GLFW_KEY_U);
		if (state == GLFW_PRESS) {
			Sleep(10);
			data->_rcube->rotateUWall();
			data->_display->Clear(1.0f, 1.0f, 1.0f, 1.0f);
			data->_rcube->render();
			data->_display->SwapBuffers();
		}
		state = glfwGetKey(window, GLFW_KEY_D);
		if (state == GLFW_PRESS) {
			Sleep(10);
			data->_rcube->rotateDWall();
			data->_display->Clear(1.0f, 1.0f, 1.0f, 1.0f);
			data->_rcube->render();
			data->_display->SwapBuffers();
		}
		state = glfwGetKey(window, GLFW_KEY_B);
		if (state == GLFW_PRESS) {
			Sleep(10);
			data->_rcube->rotateBWall();
			data->_display->Clear(1.0f, 1.0f, 1.0f, 1.0f);
			data->_rcube->render();
			data->_display->SwapBuffers();
		}
		state = glfwGetKey(window, GLFW_KEY_F);
		if (state == GLFW_PRESS) {
			Sleep(10);
			data->_rcube->rotateFWall();
			data->_display->Clear(1.0f, 1.0f, 1.0f, 1.0f);
			data->_rcube->render();
			data->_display->SwapBuffers();
		}*/
	}
	static void mouse_callback(GLFWwindow* window, int button, int action, int mods)
	{
		double x;
		double y;
		Data *data;
		data = (Data *)glfwGetWindowUserPointer(window);
		if (button == GLFW_MOUSE_BUTTON_LEFT) {
			if (GLFW_PRESS == action)
				data->_l_button = true;
			else if (GLFW_RELEASE == action)
				data->_l_button = false;
		}
		if (button == GLFW_MOUSE_BUTTON_RIGHT) {
			if (GLFW_PRESS == action)
				data->_r_button = true;
			else if (GLFW_RELEASE == action)
				data->_r_button = false;
		}
		
	}
	static void cursor_callback(GLFWwindow* window, double xpos, double ypos)
	{
		double factor = 0.01;
		Data *data;
		data = (Data *)glfwGetWindowUserPointer(window);
		double move_x = data->_curr_x - xpos;
		double move_y = data->_curr_y - ypos;
		data->_curr_x = xpos;
		data->_curr_y = ypos;
		if (data->_r_button) {
			data->_rcube->translateRCube(vec3(move_x*factor, move_y*factor, 0));
			data->_display->Clear(1.0f, 1.0f, 1.0f, 1.0f);
			data->_rcube->render();
			data->_display->SwapBuffers();
		}
		if (data->_l_button) {
			data->_rcube->rotateRCube(move_y*0.2, vec3(1, 0, 0));
			data->_rcube->rotateRCube(move_x*0.2, vec3(0, -1, 0));
			data->_display->Clear(1.0f, 1.0f, 1.0f, 1.0f);
			data->_rcube->render();
			data->_display->SwapBuffers();
		}
	}
	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
	{
		double factor = 0.2;
		Data *data;
		data = (Data *)glfwGetWindowUserPointer(window);
		data->_rcube->translateRCube(vec3(0, 0, yoffset*factor));
		data->_display->Clear(1.0f, 1.0f, 1.0f, 1.0f);
		data->_rcube->render();
		data->_display->SwapBuffers();
	}



