# AzerothCore Tracking Module

This module provides functionality for players to track both herbs and mining nodes simultaneously in the game world.

## Features

- Allows players to track both herbs and mining nodes at the same time.
- Grants a custom spell to players who have both herbalism and mining skills.
- Players can toggle the multi-gather spell on or off.

## Installation

1. Ensure you have an AzerothCore server set up and running.
2. Copy the `DoubleGatherModule.cpp` and `DoubleGatherModule.h` files into your `modules` directory.
3. Compile and install the module as per the AzerothCore documentation.
4. Modify your server's configuration file (`config.conf`) to enable the module and configure any desired options.

## Usage

Once the module is installed and enabled, players will automatically gain the ability to track both herbs and mining nodes if they have the appropriate skills. The multi-gather spell can be toggled on or off by players using a command or interface option (not provided in this module).

## Configuration

You can configure the behavior of the module by editing your server's configuration file (`config.conf`). The following options are available:

- `TrackingModule.EnableSpell`: Set this to `true` to enable the multi-gather spell feature (default: `true`).
- `TrackingModule.SpellID`: Set the spell ID for the multi-gather spell (default: `12345`).

## Credits

This module is based on the AzerothCore project (https://github.com/azerothcore/azerothcore-wotlk).

