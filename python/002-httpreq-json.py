import requests

response = requests.get('https://status.digitalocean.com/api/v2/summary.json')

json_data = response.json() if response and response.status_code == 200 else None

if json_data and 'hoststatuslist' in json_data:
    if 'hoststatus' in json_data['hoststatuslist']:
        for hoststatus in json_data['hoststatuslist']['hoststatus']:
            host_name = hoststatus.get('name')
            status_text = hoststatus.get('status_text')
            

print('test')

# ***********************************************************************

# response = requests.get('https://hacker-news.firebaseio.com/v0/item/38966145.json')
# decoded_response = response.read().decode("UTF-8")
# data = json.loads(decoded_response)
# jsonData = data["hoststatus"]

# for host in jsonData:
#     Name = host.get("name")
#     StatusText = host.get("status_text")
