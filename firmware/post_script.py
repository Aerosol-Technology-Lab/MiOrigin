import sys
import os
import shutil

Import("env", "projenv")

BINARIES_PATH = 'binaries'

def aprint(message):
    print('-> {}'.format(message))

def post_firmware_callback(source, target, env):
    print('\n====== Post Firmware ======')
    # str(env.Dump())
    # print(ast.literal_eval(str(env.Dump())))
    # for i in dir(source):
        # print(i)

    bin_path = str(target.pop())
    # target.insert(val)
    # print(env.GetProjectOptions())
    project_option = env.GetProjectOption('firmware_type')
    # print("Project option: {}".format(project_option))

    if not os.path.exists(BINARIES_PATH):
        os.mkdir(BINARIES_PATH)

    aprint('Performing checks...')

    if project_option == 'factory':
        aprint('Processing factory firmware')
        
        target_path = os.path.join(BINARIES_PATH, 'factory.bin')
        if os.path.exists(target_path):
            os.remove(target_path)

        shutil.copyfile(bin_path, target_path)
        aprint('New firmware in binaries directory')
        
    elif project_option == 'ota0':
        aprint('Processing ota0 firmware')
        
        target_path = os.path.join(BINARIES_PATH, 'firmware.bin')

        if os.path.exists(target_path):
            os.remove(target_path)

        shutil.copyfile(bin_path, target_path)
        aprint('New firmware in binaries directory')
        
    else:
        aprint('Do nothing')

# f = open('./output.txt', 'w+')
# f.write('Test')
# f.write(env.Dump())
# f.write(projenv.Dump())

# isMain = '__main__' in __name__

# print('Is this main? {}'.format(isMain))
# print('\n\nCurrent path is: {}'.format(os.getcwd()))
# print(sys.argv)

print('Running Script!')

env.AddPostAction("$BUILD_DIR/${PROGNAME}.bin", post_firmware_callback)

