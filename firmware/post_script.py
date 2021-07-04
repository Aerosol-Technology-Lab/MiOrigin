import sys
import os
import shutil

Import("env", "projenv")

BINARIES_PATH = 'binaries'

def post_firmware_callback(source, target, env):
    print('Post firmware')
    # str(env.Dump())
    # print(ast.literal_eval(str(env.Dump())))
    # for i in dir(source):
        # print(i)

    bin_path = str(target.pop())
    # target.insert(val)
    print(env.GetProjectOptions())
    project_option = env.GetProjectOption('firmware_type')
    print("Project option: {}".format(project_option))

    if not os.path.exists(BINARIES_PATH):
        os.mkdir(BINARIES_PATH)

    print('Perform checks')

    if project_option == 'factory':
        print('Factory')
        shutil.copyfile(bin_path, os.path.join(BINARIES_PATH, 'factory.bin'))
    elif project_option == 'ota0':
        print('Enter here!')
        print('Binaries path: {}'.format(BINARIES_PATH))
        print('Bin path {}'.format(bin_path))
        shutil.copyfile(bin_path, os.path.join(BINARIES_PATH, 'firmware.bin'))
        print('This is an ota')
    else:
        print('Do nothing')

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

