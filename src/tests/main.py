import pyautogui
import time

def wirte_test(num_of_test):
    write("test_" + str(num_of_test))
    write("test_" + str(num_of_test))
    write("test_" + str(num_of_test))
    write("124124")
    write("test_" + str(num_of_test))
    write("500")
    write("500")

def test_static_array():
    num = 0
    wirte_test(num)
    wirte_test(num+1)

def write(text):
        pyautogui.write(text)
        pyautogui.press("Enter")


if __name__ == '__main__':
    time.sleep(5)
    print("start testing static array")
    test_static_array()
    test_static_array()
