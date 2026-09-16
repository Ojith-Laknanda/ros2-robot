from setuptools import find_packages, setup

package_name = 'robot_car'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    package_data={'': ['py.typed']},
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ojith',
    maintainer_email='ojith@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            "teleop_robot_node = robot_car.teleop_robot:main",
            "robot_controller_node = robot_car.robot_controller:main",
            "computer_vision_engine_node = robot_car.computer_vision_engine:main",
            'behaviour_controller_node = robot_car.behaviour_controller:main',
            'display_node = robot_car.display_node:main',
            'audio_node = robot_car.audio_node:main',
            'voice_node = robot_car.voice_node:main',
        ],
    },
)
