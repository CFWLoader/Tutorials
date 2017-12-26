from scrapy.spiders import Spider

class DmozSpider(Spider):

    name = "dmoz"

    allowed_domains = ["dmoztools.net"]

    start_urls = [
            "http://www.dmoztools.net/Computers/Programming/Languages/Python/Books/",
            "http://www.dmoztools.net/Computers/Programming/Languages/Python/Resources/"
            ]

    def parse(self, response):

        filename = response.url.split("/")[-2]

        open(filename, 'wb').write(response.body)
