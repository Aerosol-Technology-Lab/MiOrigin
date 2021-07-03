# import sys
# import os
# import builtins

# Import("env", "projenv")

# BUILD_PATH = './'

# def post_firmware_callback(source, target, env):
#     print('Post firmware')
#     print(target)
#     print(dir(target))
#     print(env.__doc__)
#     print(env.GetProjectConfig())
    
#     project_option = env.GetOption('build_dir')

#     if project_option == 'factory':
#         pass
#     elif project_option == 'ota0':
#         pass
#     else:
#         # do nothing
#         pass    

# # f = open('./output.txt', 'w+')
# # f.write('Test')
# # f.write(env.Dump())
# # f.write(projenv.Dump())

# # isMain = '__main__' in __name__

# # print('Is this main? {}'.format(isMain))
# # print('\n\nCurrent path is: {}'.format(os.getcwd()))
# # print(sys.argv)

# print('Running Script!')

# env.AddPostAction("$BUILD_DIR/${PROGNAME}.bin", post_firmware_callback)

