# -----------------------------------------------------------------------
# configuration.py
# Author: Hari Raval
# -----------------------------------------------------------------------


# a Configuration object represents the parameters and settings used to generate an Amber test
class Configuration(object):

    # constructor of the Configuration object
    def __init__(self, timeout, workgroups, threads_per_workgroup, saturation_level, subgroup):
        # timeout represents the time (in ms) for which the Amber test will run
        self._timeout = timeout
        # number of workgroups to be used for the Amber test
        self._workgroups = workgroups
        # number of threads per workgroup
        self._threads_per_workgroup = threads_per_workgroup
        # type of saturation: 0 means no saturation, 1 means "round robin" saturation, 2 means "chunking" saturation
        self._saturation_level = saturation_level
        # subgroup usage: 0 means same subgroups, 1 means different subgroup and same workgroup
        self._subgroup = subgroup

    # getter method to retrieve the timeout
    def get_timeout(self):
        return self._timeout

    # getter method to retrieve the number of workgroups
    def get_number_of_workgroups(self):
        return self._workgroups

    # getter method to retrieve the number of threads per workgroup
    def get_threads_per_workgroup(self):
        return self._threads_per_workgroup

    # getter method to retrieve the type of saturation (value of 0, 1 or 2) of the Amber test
    def get_saturation_level(self):
        return self._saturation_level

    def get_subgroup_setting(self):
        return self._subgroup
