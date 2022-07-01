from selenium.webdriver.common.desired_capabilities import DesiredCapabilities
from selenium import webdriver
import time

opt = webdriver.ChromeOptions()
caps = DesiredCapabilities.CHROME
caps['goog:loggingPrefs'] = {'performance': 'ALL'}
prefs = {"download.default_directory": r"/dev/null"}
opt.add_experimental_option('perfLoggingPrefs', {'enableNetwork': True})
opt.add_experimental_option('prefs', prefs)
driver = webdriver.Chrome(executable_path="./chromedriver", options=opt, desired_capabilities=caps)

# 如果地址变了，访问 an27.cc an25.cc 等等域名获取，这个盗号狗不知道买了多少域名
driver.get("https://xjj0620.pages.dev/?lineCode=aq1")
time.sleep(2)

# 修改上面域名后，需要找到下载的位置，Chrome按F12，定位到下载位置，右键copy xpath
driver.find_element(by="xpath", value='//*[@id="downloadand"]/button/img').click()
time.sleep(1)

browser_log = driver.get_log('performance')
driver.quit()

log_str = ""
for obj in browser_log:
    log_str += obj.__str__()

pos_mid = log_str.find("aliyuncs")
pos_start = pos_end = pos_mid

while True:
    pos_start = pos_start - 1
    if log_str[pos_start] == '"':
        break

while True:
    pos_end = pos_end + 1
    if log_str[pos_end] == '"':
        break

download_url = log_str[pos_start + 1:pos_end]
print(download_url)

